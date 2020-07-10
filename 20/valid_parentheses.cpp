#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {st.push(s[i]); continue;}
            if (st.empty()) return false;
            if (s[i] == ')' && st.top() != '(') return false; 
            if (s[i] == ']' && st.top() != '[') return false;
            if (s[i] == '}' && st.top() != '{') return false;
            st.pop();
        }
        return st.empty();
        
    }
};


int main(){

  Solution s = Solution();
  std::cout << s.isValid("()") << std::endl;

}
