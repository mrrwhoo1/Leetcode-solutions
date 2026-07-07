#include <iostream>
#include <algorithm>
#include <string>


int main(){
    int nums = 121;
    std::string str_original = std::to_string(nums);
    std::string converted = std::to_string(nums);
    std::reverse(converted.begin(), converted.end());
    
    if(str_original == converted) {
        std::cout<<"True";}
    else {std::cout<<"false";}


    
}

// class Solution {
// public:
//     bool isPalindrome(int x) {
//     int nums = 121;
//     std::string str_original = std::to_string(nums);
//     std::string converted = std::to_string(nums);
//     std::reverse(converted.begin(), converted.end());
    
//     if(str_original == converted) {
//         return true;}
//     else {return false;}
        
//     }
// };