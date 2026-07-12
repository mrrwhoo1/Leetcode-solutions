#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> pairs = { {')', '('}, {']', '['}, {'}', '{'} };

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};
