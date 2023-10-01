class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;

        for (string& c : operations) {
            if (c == "+") {
                int temp = st.top();
                st.pop();
                int y = st.top() + temp;
                st.push(temp);
                st.push(y);
            } else if (c == "D") {
                int z = 2 * st.top();
                st.push(z);
            } else if (c == "C") {
                if (!st.empty()) {
                   
                    st.pop();
                }
            } else {
                int g = stoi(c);
                st.push(g);
              
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
