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
//one more kind of solution using pairs
class Solution {
public:
    pair<int, bool> helper(TreeNode* root)
    {
        if(!root)
            return {0, true};
        
        pair<int, bool> left = helper(root->left);
        pair<int, bool> right = helper(root->right);
        
        if(left.second && right.second && abs(left.first - right.first) <= 1)
            return {max(left.first,right.first)+1, true};
        
        return {max(left.first,right.first)+1, false};
    }
    
    bool isBalanced(TreeNode* root)
    {
        return helper(root).second;
    }
};
