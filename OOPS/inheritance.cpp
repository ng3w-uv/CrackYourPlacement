#include<bits/stdc++.h>
using namespace std;

class Video {
    private:
    string videoName;
    string videoLength;
    string videoAuthor;
    
    public:
    Video (string name, string length, string author){
        videoName = name;
        videoLength = length;
        videoAuthor = author;
    }
    string getVidName(){
        return videoName;
    }
    void getVidLen(){
        cout<<videoLength;
    }
    string getVidAuthor(){
        return videoAuthor;
    }
};

class Youtube {
    private:
    string name;
    list<Video> publishedVideoTitles;
    protected:
	string ownerName;
	int subscriberCount;
    public:
    void aboutMe() {
        cout<<"\n Hey! I am "<<name<<"! Subscribe to my youtube Channel! ";
    }
    
    Youtube (string name_i, string ownerName_i){
        name = name_i;
        ownerName = ownerName_i;
        subscriberCount = 0;
    }
    
    void getInfo(){
        cout<<"\n**********************************";
        cout<<"\nChannel Name : "<<name;
        cout<<"\nChannel Owner Name : "<<ownerName;
        cout<<"\nSubscriber count : "<<subscriberCount;
        int i = 1;
        for(auto it : publishedVideoTitles){
            cout<<"\n-------------"<<i++<<"---------------";
            cout<<"\nVideo Name : "<<it.getVidName();//since it is a string return type function
            cout<<"\nVideo Length : ";
            it.getVidLen();//since this is a void function..
            cout<<"\nVideo Author : "<<it.getVidAuthor();
            cout<<"\n----------------------------";
        }
        cout<<"\n**********************************";
    }
    void publishVideo(string s1,string s2, string s3){
        publishedVideoTitles.push_back(Video (s1,s2,s3));
    }
    void subs(){
        subscriberCount++;
    }
    void unsubs (){
        if(subscriberCount>0){
            subscriberCount--;
        }
    }
    
    void setName (string n) {
        name = n;
    }
};

class CookingYoutubeChannel : public Youtube {
	public:
	CookingYoutubeChannel (string nm,string onm) : Youtube(nm,onm){
		
	}	
	void practiceCooking(){
		cout<<"\n"<<ownerName<<" likes to cook and pakau...and has "<<subscriberCount<<" subscribers";
	}
};

int main() {
    Youtube channel_1("Ng3w","UV");
    Youtube channel_2("Monkey Baba","Ng3w");
    
    channel_1.publishVideo("Learn C++ easy","2hrs","Ng3w");
    channel_1.publishVideo("Learn Python easy","1hrs","Ng3w");
    
    channel_2.publishVideo("Learn to code easy","1hrs","Random Baba");
    channel_2.publishVideo("Learn to code the Hard","3hrs","OP Baba");
	
    for(int i = 0;i<10;i++){
        channel_1.subs();
    }
    channel_1.unsubs();
    
    channel_1.aboutMe();
    channel_1.getInfo();
    
    channel_2.aboutMe();
    channel_2.setName("UV the BABA");
    channel_2.getInfo();
    
    CookingYoutubeChannel channel_3("Cooking Shooking","Sajeev kapoor");
    channel_3.publishVideo("Paneer Makhani easy","1hrs","Sanjeev");
    channel_3.publishVideo("Paneer Kadai easy","1hrs","Sanjeev");
    channel_3.aboutMe();
    channel_3.subs();
    channel_3.practiceCooking();
    channel_3.getInfo();
	
	
	return 0;
}

/* OUTPUT

 Hey! I am Ng3w! Subscribe to my youtube Channel! 
**********************************
Channel Name : Ng3w
Channel Owner Name : UV
Subscriber count : 9
-------------1---------------
Video Name : Learn C++ easy
Video Length : 2hrs
Video Author : Ng3w
----------------------------
-------------2---------------
Video Name : Learn Python easy
Video Length : 1hrs
Video Author : Ng3w
----------------------------
**********************************
 Hey! I am Monkey Baba! Subscribe to my youtube Channel! 
**********************************
Channel Name : UV the BABA
Channel Owner Name : Ng3w
Subscriber count : 0
-------------1---------------
Video Name : Learn to code easy
Video Length : 1hrs
Video Author : Random Baba
----------------------------
-------------2---------------
Video Name : Learn to code the Hard
Video Length : 3hrs
Video Author : OP Baba
----------------------------
**********************************
 Hey! I am Cooking Shooking! Subscribe to my youtube Channel! 
Sajeev kapoor likes to cook and pakau...and has 1 subscribers
**********************************
Channel Name : Cooking Shooking
Channel Owner Name : Sajeev kapoor
Subscriber count : 1
-------------1---------------
Video Name : Paneer Makhani easy
Video Length : 1hrs
Video Author : Sanjeev
----------------------------
-------------2---------------
Video Name : Paneer Kadai easy
Video Length : 1hrs
Video Author : Sanjeev
----------------------------
**********************************
*/
