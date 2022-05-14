//just take last element in each level
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> lev;
            
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                lev.push_back(node->val);
            }
            result.push_back(lev[lev.size()-1]);
        }
        return result;
    }
};
