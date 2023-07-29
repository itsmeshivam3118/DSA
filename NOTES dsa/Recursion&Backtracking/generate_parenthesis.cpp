//https://leetcode.com/problems/generate-parentheses/

//https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

//https://www.youtube.com/watch?v=eyCj_u3PoJE&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=17&ab_channel=AdityaVerma

class Solution {
public:
        void solve(int open,int close,string op,vector<string>&v)
    {
        if(open==0&&close==0)
        {
            v.push_back(op);
            return;
        }
        if(open!=0)
        {
             
            solve(open-1,close,op+'(',v);
               
        }
        if(close>open)
        {
             
            solve(open,close-1,op+')',v);
               
        }
        return;
        }
                
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        int close=n;
        int open=n;
        string op="";
        solve(close,open,op,v);
        return v;
    }
};