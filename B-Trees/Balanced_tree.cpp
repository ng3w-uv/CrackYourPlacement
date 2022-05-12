class Solution {
public:
    int dfsHeight(TreeNode* node){
        if(node==NULL) return 0;
        
        int leftHeight = dfsHeight(node->left);
        if(leftHeight == -1) return -1;
        
        int rightHeight = dfsHeight(node->right);
        if(rightHeight == -1) return -1;
        
        if(abs(rightHeight - leftHeight) > 1) return -1;
        
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {  
        return dfsHeight(root) != -1;
    }
};
