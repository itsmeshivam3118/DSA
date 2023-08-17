//https://www.youtube.com/watch?v=XLdpy0_6MR4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=73&ab_channel=CodeHelp-byBabbar

//https://practice.geeksforgeeks.org/problems/burning-tree/1


class Solution {
  public:
  Node* nodetoparent(Node* root, int target, map<Node*, Node*> &m){
      Node* node=NULL;
      queue<Node*> q;
      q.push(root);
      m[root]=NULL;
      
      while(!q.empty()){
          Node* front=q.front();
          q.pop();
          
          if(front->data==target){
              node=front;
          }
          
          if(front->left){
              m[front->left]=front;
              q.push(front->left);
          }
          if(front->right){
              m[front->right]=front;
              q.push(front->right);
          }
      }
      
      return node;
  }
  
  void burningtime(Node* node, int target, map<Node*, Node*> m, int &time){
     map<Node*, bool> visited;
      queue<Node*> q;
      
      visited[node]=true;
      
      q.push(node);
      while(!q.empty()){
          bool flag=false;
          int size=q.size();
          
          for(int i=0; i<size; i++){
              Node* temp=q.front();
              q.pop();
              
              if(temp->left and visited[temp->left]==false){
                  flag=true;
                  q.push(temp->left);
                  visited[temp->left]=true;
              }
              
              if(temp->right and visited[temp->right]==false){
                  flag=true;
                  q.push(temp->right);
                  visited[temp->right]=true;
              }
              
              if(m[temp] and visited[m[temp]]==false){
                  flag=true;
                  q.push(m[temp]);
                  visited[m[temp]]=true;
              }
          }
          if(flag==true) time++;
      }
  }
  
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> m;
        Node* node=nodetoparent(root, target, m);
        int time=0;
        burningtime(node, target, m, time);
        return time;
    }
};
