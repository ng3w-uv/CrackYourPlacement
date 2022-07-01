https://practice.geeksforgeeks.org/problems/calculate-time-required-to-type-a-word-using-given-single-row-keyboard/0/?track=gts-strings&batchId=397#
class Solution{
public:
	int timeTakenToType(string keyboardLayout, string word){
        unordered_map<char,int> map;
        
        for(int i = 0;i<keyboardLayout.size();i++){
            map[keyboardLayout[i]] = i+1;
        }
        
        int pre = 1,ans = 0;
        for(int i = 0;i<word.size();i++){
            auto it = map.find(word[i]);
            if(it!=map.end()){
                int current = it->second;
                ans += abs(current - pre);
                pre = current;
            }
        }
        return ans;
        
    }
};
