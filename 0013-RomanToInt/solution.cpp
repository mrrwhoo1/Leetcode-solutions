#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    string user;
    int total = 0;

    unordered_map<string, int> characters;
    characters = {
        { "I", 1 },
        { "V", 5 },
        { "X", 10 },
        { "L", 50 },
        { "C", 100 },
        { "D", 500 },
        { "M", 1000 },
    };

    vector<int> nums;

    cout << "Enter symbol: ";
    cin >> user;
    for (int i = 0; i < user.length(); i++) {
        string current_letter(1, user[i]);
        int value = characters[current_letter];
        nums.push_back(value);
        // cout << "[" << current_letter << "] length: " << current_letter.length() << endl;
    }

    cout << "Your values in the vector are: ";
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
    cout << total << endl;
}
