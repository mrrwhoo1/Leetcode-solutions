#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string first_name = strs[0];
        for (int index = 1; index < strs.size(); index++) {
            while (!strs[index].starts_with(first_name)) {
                first_name = first_name.substr(0, first_name.length() - 1);
            }
        }
        return first_name;
    }
};

int main()
{
    Solution obj;
    vector<string> strs = { "maron", "martha", "martin" };
    string result = obj.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}
