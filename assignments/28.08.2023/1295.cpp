class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i:nums){
            string a=to_string(i);
            if(a.size()%2==0)
            count++;
        }
        return count;
    }
};