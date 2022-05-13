/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* node){
        
        if (node == NULL) return NULL;
        
        swap(node->left,node->right);
        
        invertTree(node->left);
        invertTree(node->right);
        
        return node;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q){
        
        if(p == NULL || q == NULL){
            return (p==q);
        }
        
        return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if(!root) return NULL;
        
        TreeNode* t1 = root->left;
        TreeNode* t2 = root->right;
        
        invertTree(t1);
        
        return isSameTree(t1,t2);    
    }
};
