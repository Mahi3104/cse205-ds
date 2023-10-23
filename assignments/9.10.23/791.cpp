class Solution {
public:
    string customSortString(string order, string s) {
       unordered_map<char,int>um;
       for(auto j:s)
        um[j]++;
        string ans;
        for(auto it:order)
        {
            for(int i=0;i<um[it];i++)
             ans+=it;
            um[it]=0;
        }
        for(auto it:um)
        {
            for(int i=0;i<it.second;i++)
             ans+=it.first;
        }
        return ans;
    }
};