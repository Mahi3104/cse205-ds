class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
   
// Used for breaking words
stringstream ss(s);
map<char,string>m1;
// To store individual words
string Word;
 int i=0;
map<string,char>m2;
while (ss >> Word)
   {
    auto it= m1.find(pattern[i]);
    auto it1=m2.find(Word);
     if(it==m1.end()&&it1!=m2.end()||it!=m1.end()&&it1==m2.end())
     return false;
     if(it!=m1.end()&&it1!=m2.end()){
         if(it->second!=Word)return false;
         if(it1->second!=pattern[i])return false;
     }
      if(it==m1.end()&&it1==m2.end()){     
      m1[pattern[i]]=Word;
      m2[Word]=pattern[i];
     
      }
       i++;
      
   }
if(i>=pattern.size())//if the string traversed that is for every character a word is mapped.
return true;
return false;
//when there are no enough words for the characters we simply return false
    }
};