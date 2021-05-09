#include <algorithm>
class Solution {
public:
	int minArray(vector<int>& numbers) {
		if (numbers.size() == 0)
			return{};
		sort(numbers.begin(), numbers.end());
		return numbers[0];
	}
};