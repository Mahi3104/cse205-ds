class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
         if(s[0]==')'||s[0]==']'||s[0]=='}')
            return false;
     for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            } else if (c == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            } else if (c == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            } else {
                return false; 
            }
        }
    if(st.empty()){
        return true;
    }
    else
    return false;
    }
};