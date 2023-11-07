class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq(nums.begin(),nums.end());
        int maxx=pq.top()-1;
        pq.pop();
        int secmaxx=pq.top()-1;
        return maxx*secmaxx;
    }
};