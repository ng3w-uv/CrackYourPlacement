https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/0/?track=gts-strings&batchId=397#
class Solution{
  public:
    bool validPrefix(string pre,string s){
        for(int i = 0;i<pre.size();i++){
            if(pre[i]!=s[i]){
                return false;
            }
        }
        return true;
    }
    string longestCommonPrefix (string arr[], int N)
    {
        /*
        string v;
        int d = 0;
        bool flag = true;
        while(true){
            
            char ch = arr[0][d];
            if(ch == '\0'){
                break;
            }
            for(int i = 1;i<N;i++){
                if(arr[i][d]!=ch){
                    flag = false;
                }
            }
            if(flag){
                v.push_back(ch);
            }
            else{
                break;
            }
            d++;
        }
        if(v.size()>0){
            return v;
        }
        else{
            return "-1";
        }
        */
        
        //Another method that we can use is that we initialise a prefix and then keep on reducing it as we glide through all the strings
        string pre = arr[0];
        
        for(int i = 1;i<N;i++){
            while(!validPrefix(pre,arr[i])){
                pre.pop_back();
            }
        }
        if(pre.size()>0){
            return pre;
        }
        else{
            return "-1";
        }
        
        //TRIE METHOD
      
        //though this method did not improve any time compaexity ...although took up space complexity..this is generally avoided...
        //There is one more method...which includes the use of trie...
        //so we add each string in the trie and then traverse...
        //all nodes with one child would be added in the answer...
        //whichever node has more than one child we break over that...
        //we also break over terminal nodes...
    }
};
