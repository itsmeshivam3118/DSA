//https://www.youtube.com/watch?v=BmZnJehDzyU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=60&ab_channel=CodeHelp-byBabbar

//https://www.codingninjas.com/codestudio/problems/redundant-brackets_975473?leftPanelTab=1


#include<stack>
bool findRedundantBrackets(string &s)
{    stack<char>st;
 bool x;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='('||ch=='+'||ch=='*'||ch=='-'||ch=='/')
            st.push(ch);
        else{
            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                    if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/')
                        isRedundant=false;
                    st.pop();
                }
                 if(isRedundant == true)
                    return true;
                st.pop();
            }
            
            
        }
    }
 return false;
}
