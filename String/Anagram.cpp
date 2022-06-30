https://practice.geeksforgeeks.org/problems/anagram-1587115620/0/?track=gts-strings&batchId=397#
class Solution
{
    public:
    bool isAnagram(string a, string b){
        /*vector<int> v(26,0);
        
        for(int i = 0;a[i]!='\0';i++){
            v[a[i]-97]++;
        }
        
        for(int i = 0;b[i]!='\0';i++){
            v[b[i]-97]--;
        }
        
        for(int i = 0;i<26;i++){
            if(v[i]!=0){
                return false;
            }
        }
        return true;*/
        
        unordered_map<char,int> m;
        for(int i = 0;i<a.length();i++){
            m[a[i]]++;
        }
        for(int i = 0;i<b.length();i++){
            m[b[i]]--;
        }
        for(auto it:m){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};
