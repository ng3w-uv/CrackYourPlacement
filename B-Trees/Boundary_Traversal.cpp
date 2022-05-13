bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}


//one more method...involving more...recursive methods...
void leftVeiw(TreeNode<int> * root , vector<int>&ans){
   if(root == NULL){
       return ;  
   }
   if(root -> left == NULL and root -> right == NULL ){
       return ;  
   }
   ans.push_back(root -> data) ;  
   leftVeiw(root -> left , ans) ;  
   if(root -> left == NULL ){
       leftVeiw(root -> right , ans ) ;  
       return ;  
   }
   return ;  
}
void leafNodes(TreeNode<int> * root , vector<int> & ans){
   if(root == NULL){
       return ;  
   }
   if(root -> left == NULL and root -> right == NULL){
       ans.push_back(root->data) ;  
       return ;  
   }
   leafNodes(root -> left , ans) ;  
   leafNodes(root -> right , ans) ;  
   return ;  
}
void rightVeiw(TreeNode<int> * root , vector<int> & ans){
   if(root == NULL){
       return ;  
   }
   if(root->right == NULL and root -> left == NULL){
       return ;  
   }
   rightVeiw(root -> right, ans) ;  
   if(root -> right == NULL){
       rightVeiw(root -> left , ans) ;  
   }
   ans.push_back(root -> data) ;  
   return ;  
}
vector<int> traverseBoundary(TreeNode<int>* root){
   vector<int> ans;  
   if(!root){
       return ans ;  
   }
   ans.push_back(root -> data) ;  
   if(root -> left){
       leftVeiw(root->left , ans) ;  
   }
   leafNodes(root->left, ans) ;  
   leafNodes(root -> right , ans) ;  
   if(root -> right){
       rightVeiw(root -> right , ans ) ;  
   }
   return ans ;  
}
