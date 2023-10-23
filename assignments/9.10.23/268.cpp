class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp;
        sort(nums.begin(),nums.end());
       int i=0;
       while(i<nums.size()){
           if(nums[i]!=i){
               temp=i;
               break;
           }
           i++;
       }
       return temp;
    }
};