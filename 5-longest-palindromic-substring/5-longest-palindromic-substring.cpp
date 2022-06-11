class Solution {
public:
    string longestPalindrome(string s) {
        int resultLength = 0;
        string result = "";
        int n = s.size(); 
        
        for(int i = 0;i<n;i++){
            
            //we are using expand from the middle char concept
            //checking for odd length
            int l = i,r = i;
            while(l>=0 && r < n && s[l]==s[r]){
                if((r-l+1)>resultLength){
                    result = s.substr(l,(r-l+1));
                    resultLength = r-l+1;
                }
                l -= 1;
                r += 1;
            }
            
            //checking for even length
            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if((r-l+1)>resultLength){
                    result = s.substr(l,(r-l+1));
                    resultLength = r-l+1;
                }
                l -= 1;
                r += 1;
            }
            
        }
        return result;
    }
};