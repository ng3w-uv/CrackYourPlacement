https://practice.geeksforgeeks.org/problems/unique-email-addresses/0/?track=gts-strings&batchId=397#
class Solution
{
   public:
   string filter(string str){
       string s = "";
       bool flag = false;
       int i = 0;
       for(i = 0;str[i] != '@';i++){
           if(flag == true || str[i]=='.') continue;
           if(str[i]=='+'){
               flag = true;
               continue;
           }
           s+=str[i];
       }
       return s+str.substr(i);
   }
    int UniqueEmails(vector<string>emails){
    	//simply iterate over 
    	//simple implementation
    	
    	set<string> s1;
    	
    	for(auto &it:emails){
    	    s1.insert(filter(it));
    	}
    	
    	return s1.size();
    }
};
