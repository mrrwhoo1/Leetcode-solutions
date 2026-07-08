#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<string, int> characters = {
            { "I", 1 },
            { "V", 5 },
            { "X", 10 },
            { "L", 50 },
            { "C", 100 },
            { "D", 500 },
            { "M", 1000 },
        };

        vector<int> nums;
        for (int i = 0; i < s.length(); i++) {
            string current_letter(1, s[i]);
            int value = characters[current_letter];
            nums.push_back(value);
        }

        int total = 0;
        for (int index = 0; index < nums.size(); index++) {
            int next_index = index + 1;
            int current_val = nums[index];

            if (next_index < nums.size()) {
                int next_val = nums[next_index];
                if (current_val < next_val) {
                    total -= current_val;
                } else {
                    total += current_val;
                }
            } else {
                total += current_val;
            }
        }

        return total;
    }
};
