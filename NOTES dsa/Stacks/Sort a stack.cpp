//https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

//https://www.geeksforgeeks.org/sort-a-stack-using-recursion/

//https://www.youtube.com/watch?v=BmZnJehDzyU&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=60&ab_channel=CodeHelp-byBabbar


void sortedInsert(stack<int> &stack,int x){
    if(stack.empty()||stack.top()<x){
        stack.push(x);
        return;
    }
    int y=stack.top();
    stack.pop();
    sortedInsert(stack,x);
    stack.push(y);
    
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
        return;
    
    int x=stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack,x);
}