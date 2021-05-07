class Solution {
	public int maxSubArray(int[] nums) {
		int max = nums[0];
		int former = 0;//用于记录dp[i-1]的值，对于dp[0]而言，其前面的dp[-1]=0
		int cur = nums[0];//用于记录dp[i]的值
		for (int num : nums){
			cur = num;
			if (former>0) cur += former;
			if (cur>max) max = cur;
			former = cur;
		}
		return max;
	}
}


class Solution {
	public int maxSubArray(int[] nums) {
		int cur = nums[0];//用来记录当前的值
		int max = nums[0];
		int prev = 0;//用来记录前n-1个值的最大值

		for (int num : nums)
		{
			cur = num;
			if (prev > 0)
				cur = prev + cur;
			if (cur > max)
				max = cur;
			prev = cur;
		}
		return max;
	}
}