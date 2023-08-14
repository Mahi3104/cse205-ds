class Solution {
public:
    void reverseString(vector<char>& s,int left=0,int right=-1) {
      if(right==-1){
        right=s.size()-1;
      }
      
     if(left>=right){
         return;
     }
     swap(s[left],s[right]);
      reverseString(s,left+1,right-1);
    }

};