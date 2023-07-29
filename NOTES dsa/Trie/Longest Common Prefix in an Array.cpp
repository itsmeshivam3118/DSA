https://www.geeksforgeeks.org/longest-common-prefix-using-trie/

https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

https://www.youtube.com/watch?v=VTr3Nh7BadI&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=88&t=11s


class Solution{
  public:
  struct TrieNode
{
    struct TrieNode *children[26];
  
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

  struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
  
    if (pNode)
    {
        int i;
  
        pNode->isLeaf = false;
  
        for (i = 0; i < 26; i++)
            pNode->children[i] = NULL;
    }
  
    return pNode;
}

  void insert(struct TrieNode *root, string key)
{
    int length = key.length();
    int index;
  
    struct TrieNode *pCrawl = root;
  
    for (int level = 0; level < length; level++)
    {
        index = key[level] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
  
        pCrawl = pCrawl->children[index];
    }
  
    // mark last node as leaf
    pCrawl->isLeaf = true;
}

  void constructTrie(string arr[], int n, struct TrieNode *root)
{
    for (int i = 0; i < n; i++)
        insert (root, arr[i]);
    return;
}

int countChildren(struct TrieNode *node, int &index)
{
    int count = 0;
    for (int i=0; i<26; i++)
    {
        if (node->children[i] != NULL)
        {
            count++;
            index = i;
        }
    }
    return (count);
}

string walkTrie(struct TrieNode*root, string &ans){
    struct TrieNode *temp = root;
    int index;
    
    
    while(countChildren(temp, index) == 1 && temp->isLeaf == false){
        temp = temp->children[index];
        ans.push_back(index+'a');
    }
    return ans;
}
    
    string longestCommonPrefix (string arr[], int N)
    {
    string ans = "";
    struct TrieNode *root = getNode();
    constructTrie(arr, N, root);
    ans = walkTrie(root, ans);
    if(ans=="")
    return "-1";
    else
    return ans;
    }
};