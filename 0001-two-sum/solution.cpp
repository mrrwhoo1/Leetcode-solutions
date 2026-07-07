#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        unordered_map<int, int> seen;

        for (int index = 0; index < nums.size(); index++) {
            int value = nums[index];
            int complement = target - value;
            auto it = seen.find(complement);
            if (it != seen.end()) {
                return { it->second, index };
            }
            seen[value] = index;
        }
        return {};
    }
};
