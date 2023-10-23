class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int p1=0;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){
                if(arr1[j]==arr2[i]){
                    swap(arr1[p1],arr1[j]);
                    p1++;
                }
            }
        }
        sort(arr1.begin()+p1,arr1.end());
        return arr1;
    }
};