class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int minn=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            minn=min(minn,arr[i+1]-arr[i]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==minn){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};