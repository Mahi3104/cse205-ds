
class Solution {
public:
    void help(int i,vector<int>&candidates,int target,int sumtillnow,vector<int>&subset,vector<vector<int>>&ans){
        if(sumtillnow==target){
            ans.push_back(subset);
            return;
        }
        if(sumtillnow>target)return;

        if(i>=candidates.size())return;

        help(i+1,candidates,target,sumtillnow,subset,ans);

        sumtillnow+=candidates[i];
        subset.push_back(candidates[i]);
        help(i,candidates,target,sumtillnow,subset,ans);
        
        sumtillnow-=candidates[i];
        subset.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>subset;
        vector<vector<int>>ans;
        int sumtillnow=0;
        sort(candidates.begin(),candidates.end());
        help(0,candidates,target,sumtillnow,subset,ans);
        return ans;
    }
};