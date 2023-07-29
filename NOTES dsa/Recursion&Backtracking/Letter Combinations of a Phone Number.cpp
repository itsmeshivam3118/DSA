//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

//https://www.youtube.com/watch?v=tWnHbSHwNmA&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=42&ab_channel=CodeHelp-byBabbar

class Solution {
        
       void solve(string digits,vector<string>&ans,int index,string mapping[],string output){
              
               
               
               if(index>=digits.length()){
                        ans.push_back(output);
                       return ;
               }
               
               int number=digits[index]-'0';
               string value=mapping[number];
               
               
               
               
               for(int i=0; i<value.length();i++){
                       output.push_back(value[i]);
                       solve(digits,ans,index+1,mapping,output);
                       output.pop_back();
               }
               
               
                      
        }
        
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
            if(digits.length()==0) return ans;
             int index=0;
             string output;
             string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            solve(digits,ans,index,mapping,output);
            return ans;
    }
};