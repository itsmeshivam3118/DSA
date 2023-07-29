//https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

//https://www.youtube.com/watch?v=BmZnJehDzyU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=60&ab_channel=CodeHelp-byBabbar





bool valid(string s)
{
     stack<char> st;
     for(int i=0; i<s.length(); i++) {
         
         char ch = s[i];
         
         //if opening bracket, stack push
         //if close bracket, stacktop check and pop
         
         if(ch == '(' || ch == '{' || ch == '['){
             st.push(ch);
         }
         else
         {
             //for closing bracket
             if(!st.empty()) {
                  char top = st.top();
                  if( (ch == ')' && top == '(') || 
                     ( ch == '}' && top == '{') || 
                     (ch == ']' && top == '[') ) {
                      st.pop();
                  }
                 else
                 {
                     return false;
                 }
             }
             else
             {
                 return false;
             } 
         }  
     }
    
    if(st.empty())
        return true;
    else
        return false;
}