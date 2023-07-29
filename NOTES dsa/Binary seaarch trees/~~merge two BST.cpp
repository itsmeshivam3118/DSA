https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

https://youtu.be/18w8VduomfI?list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA


void BSTToDLL(TreeNode<int> *root,TreeNode<int> * &head){

   if( root == NULL)
       return;

   BSTToDLL( root->right,head);
   root->right = head;

   if(head != NULL)
       head->left = root; 

   head = root;

   BSTToDLL(root->left,head);
}

 

TreeNode<int>* mergeSortedDLL(TreeNode<int> *head1,TreeNode<int> *head2){

   if(head1 == NULL)
       return head2;

   if(head2 == NULL)
       return head1;
    
   TreeNode<int> *head = NULL;
   TreeNode<int> *tail = NULL;

   while(head1!= NULL && head2!=NULL) {
     if(head1->data <head2->data){

           if(head == NULL){

             head = head1;

               tail = head1;

               head1 = head1->right;

           }

           else{

               tail ->right = head1;

               head1->left = tail;

               tail =head1;

               head1 = head1->right;

           }

       }

       else{

           if(head == NULL){

             head = head2;

               tail = head2;

               head2 = head2->right;

           }

           else{

               tail ->right = head2;

               head2->left = tail;

               tail =head2;

               head2 = head2->right;

           }

       }

   }

   

   while(head1 != NULL){

       tail->right = head1;

       head1->left = tail;

       tail = head1;

       head1=head1->right;

   }

    while(head2 != NULL){

       tail->right = head2;

       head2->left = tail;

       tail = head2;

       head2=head2->right;
  }
   return head;
}

int countNodes(TreeNode<int> * head){

   TreeNode<int> *temp = head;

   int count =0;

   while(temp!=NULL){

       count ++;

       temp=temp->right;
 }
   return count;
}

TreeNode<int>* sortedDLLToBST(TreeNode<int>* &head,int n){

   if(n<=0 || head == NULL)
       return NULL;

   TreeNode<int>* left = sortedDLLToBST(head,n/2);

   TreeNode<int>* root = head;

   root->left = left;

   head = head->right;

   root->right = sortedDLLToBST(head,n-n/2-1);

   return root;

}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){

   // Write your code here.

   TreeNode<int> *head1 = NULL;

   BSTToDLL(root1,head1);

   head1->left = NULL;

   TreeNode<int> *head2 = NULL;

   BSTToDLL(root2,head2);

   head2->left = NULL;

   TreeNode<int>* head = mergeSortedDLL(head1,head2);

   int count = countNodes(head);

 return  sortedDLLToBST(head,count);
 
}