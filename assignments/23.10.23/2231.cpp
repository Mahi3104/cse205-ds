class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int>odd;
        priority_queue<int>even;
        vector<int>digit,res;
        while(num){
            int rem=num%10;
            digit.push_back(rem);
            if(rem%2==0){
                even.push(rem);
            }
            else{
                odd.push(rem);
            }
            num=num/10;
        }
        for(int i=digit.size()-1;i>=0;i--){
            if(digit[i]%2==0)
            {
                res.push_back(even.top());
                even.pop();
            }
            else{
                res.push_back(odd.top());
                odd.pop();
            }
        }
        int maxnum=0;
        for(int i=0;i<res.size();i++){
            maxnum=maxnum*10+res[i];
        }
        return maxnum;
    }
};