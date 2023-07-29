https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

https://youtu.be/_9F2VgZcvdw?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA

class Solution {
  public:
  bool isCBT(struct Node* tree, int index, int totalCount){
      
      if(tree == NULL)
      return true;
      
      if(index >= totalCount)
      return false;
      else{
      bool left = isCBT(tree->left, 2*index +1, totalCount);
      bool right = isCBT(tree->right, 2*index +2, totalCount);
      return (left && right);
      }
  }
  
  bool isMaxOrder(struct Node* tree){
      //if leaf node
      if(tree->left == NULL && tree->right == NULL)
      return true;
      
      //if only left node exists
      if(tree->right == NULL)
          return(tree->data > tree->left->data);
      //if both nodes exists
      else
      {
          bool left = isMaxOrder(tree->left);
          bool right = isMaxOrder(tree->right);
          
          return(left && right && (tree->data>tree->left->data && tree->data>tree->right->data));
      }
          
  }
  
  int countNodes(struct Node* tree){
      if(tree == NULL)
      return 0;
      
      return 1+countNodes(tree->left)+countNodes(tree->right);
  }
    bool isHeap(struct Node* tree) {
        int index = 0;
        int totalCount = countNodes(tree);
        return (isCBT(tree, index, totalCount) && isMaxOrder(tree));
    }
};