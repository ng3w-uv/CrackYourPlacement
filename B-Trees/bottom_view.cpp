void Inorder(BinaryTreeNode<int> * node,map<int,int> &mp, int dist){
    if(node==NULL) return;
    
    map<int, int>::iterator it = mp.find(dist); 
    
    if (it != mp.end())
        it->second = node->data;
    else
        mp.insert(pair<int,int>(dist,node->data));
    
    if(node->left) Inorder(node->left,mp,dist-1);
    if(node->right) Inorder(node->right,mp,dist+1);
}

vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int,int> mp;
    Inorder(root,mp,0);
    
    vector<int> v;
    for(auto &it:mp){
        v.push_back(it.second);
    }
    return v;
}

20 8 22 5 3 -1 25 -1 -1 10 14 -1 -1 -1 -1 -1 -1 

-> should come 5 10 3 14 25
-> mine .......5 10 3 22 25

mp[root->data] = 0;
        \\
mp[0] = root->data;


//Correct Appraoch...

vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int,int> mp;
    queue<pair<int,BinaryTreeNode<int> * >> q;
    q.push({0,root}); 
    mp[0] = root->data;
    
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            pair<int,BinaryTreeNode<int> *> p = q.front();
            BinaryTreeNode<int> * node = p.second;
            int dist = p.first;
            mp[dist] = node->data;
            q.pop();
            
            if(node->left) q.push({dist-1,node->left});
            if(node->right) q.push({dist+1,node->right});
        }
    }
    
    vector<int> v;
    for(auto &it:mp){
        v.push_back(it.second);
    }
    return v;
}
