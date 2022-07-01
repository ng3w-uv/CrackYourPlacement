https://practice.geeksforgeeks.org/problems/swap-adjacent-in-lr-string/0/?track=gts-strings&batchId=397
class Solution {
public:
    bool canTransform(string S, string T) {
        int l = S.size();
        int s = 0;
        int e = 0;
        
        while(1){
            while(s<l && S[s] == 'X'){
                s += 1;
            }
            while(e<l && T[e] == 'X'){
                e += 1;
            }
            if(s == l || e == l){
                return s == l && e == l;
            }
            if(S[s] != T[e]){
                return false;
            }
            if(S[s] == 'R' && s>e){
                return false;
            }
            if(S[s] == 'L' && s<e){
                return false;
            }
            s += 1;
            e += 1;
        }
        return true;
    }
};
