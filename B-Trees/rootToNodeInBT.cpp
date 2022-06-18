/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool getPath(TreeNode* root, vector<int> &v, int x){
    if(!root){
        return false;
    }
    v.push_back(root->val);
    if(root->val == x){
        return true;
    }
    
    if(getPath(root->left,v,x) || getPath(root->right,v,x)){
        return true;
    }
    
    v.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    if(A==NULL){
        return v;
    }
    
    getPath(A,v,B);
    return v;
}
