#include <iostream>
#include <algorithm>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
    int nums = 121;
    std::string str_original = std::to_string(nums);
    std::string converted = std::to_string(nums);
    std::reverse(converted.begin(), converted.end());
    
    if(str_original == converted) {
        return true;}
    else {return false;}
        
    }
};