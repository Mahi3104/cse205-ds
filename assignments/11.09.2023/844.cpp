class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1,st2;
        for(char c1:s){
            if(c1!='#')
                st1.push(c1);
            
            else if(!st1.empty())
            st1.pop();
        }
        for(char c2:t){
            if(c2!='#')
                st2.push(c2);
            
            else if(!st2.empty())
            st2.pop();
        }
        if(st1==st2)
        return true;
        else
        return false;
    }
};