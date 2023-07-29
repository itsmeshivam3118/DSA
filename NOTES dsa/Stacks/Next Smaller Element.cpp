//https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

//https://www.geeksforgeeks.org/next-smaller-element/

//https://www.youtube.com/watch?v=lJLcqDsmYfg&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=61&ab_channel=CodeHelp-byBabbar


#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>st;
    st.push(-1);
    vector<int>v(n);
    for(int i=n-1;i>=0;i--){
       while(st.top()>=arr[i]){
           st.pop();
       }
        v[i]=st.top();
        st.push(arr[i]);
    }
    return v;
}