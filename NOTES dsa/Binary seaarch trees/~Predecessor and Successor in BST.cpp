https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

https://youtu.be/pDURIj98e0I?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA





void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

Node*temp = root;
    
    
    while(key!=temp->key){
        if(key<temp->key){
          suc = temp;
          temp = temp->left;
    }
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }
    
    Node*leftTree = temp->left;
    while(leftTree!=NULL){
        pre = leftTree;
        leftTree = leftTree->right;
    }
    Node*rightTree = temp->right;
    while(rightTree!=NULL){
        suc = rightTree;
        rightTree = rightTree->left;
    }
    

}