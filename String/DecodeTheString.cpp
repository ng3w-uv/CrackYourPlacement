https://practice.geeksforgeeks.org/problems/decode-the-string2444/0/?track=gts-strings&batchId=397
class Solution{
public:
    string decodedString(string s){
    stack<string> st_str;
    stack<int> counts;
    
    string res = "";
    int i = 0;
    
    while(i < s.length()){
        if(isdigit(s[i])){
            //since there can be all kinds of didgits...ones ...tens ...etc
            int count = 0;
            while(isdigit(s[i])){
                count = 10 * count + (s[i]-'0');
                i++;
            }
            counts.push(count);
        }
        else if(s[i]=='['){
            st_str.push(res);
            res = "";
            i++;
        }
        else if(s[i]==']'){
            string temp = st_str.top();
            st_str.pop();
            int count = counts.top();
            counts.pop();
            for(int x = 0;x<count;x++){
                temp.append(res);
            }
            res = temp;
            i++;
        }
        else{
            //it is a normal alphabet
            res += s[i];
            i++;
        }
    }
    return res;

    }
};
