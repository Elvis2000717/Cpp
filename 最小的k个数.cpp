#include <algorithm>
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (k == 0)
			return{};

		vector<int> it;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < k; i++)
		{
			it.push_back(arr[i]);
		}
		return it;
	}
};