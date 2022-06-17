#include<bits/stdc++.h>
using namespace std;

class Video {
    public:
    string videoName;
    string videoLength;
    string videoAuthor;
    
    Video (string name, string length, string author){
        videoName = name;
        videoLength = length;
        videoAuthor = author;
    }
};

class Youtube {
    public:
    string name;
    string ownerName;
    int subscriberCount;
    list<Video> publishedVideoTitles;
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
            cout<<"\nVideo Name : "<<it.videoName;
            cout<<"\nVideo Length : "<<it.videoLength;
            cout<<"\nVideo Author : "<<it.videoAuthor;
            cout<<"\n----------------------------";
        }
        cout<<"\n**********************************";
    }
};

class Student : public Youtube {
    public:
    void aboutMe() {
        cout<<"\n Hey! I am a Student ";
    }
};

int main() {
    Youtube channel_1("Ng3w","UV");
    Youtube channel_2("Monkey Baba","Ng3w");
    
    Video v1("Learn C++","2 hrs","Ng3w baba");
    Video v2("Learn C#","2 hrs","Ng3w baba");
    
    channel_1.publishedVideoTitles.push_back(Video ("Learn Python","1 hr","Random Baba"));
    channel_1.publishedVideoTitles.push_back(v1);
    channel_1.publishedVideoTitles.push_back(v2);
    
    channel_2.publishedVideoTitles.push_back(Video("Learn how to Clean Code","3 hrs","New Baba"));
    channel_2.publishedVideoTitles.push_back(Video("Learn Git/Github","1 hrs","N Baba"));
    
    channel_1.aboutMe();
    channel_1.getInfo();
    channel_2.aboutMe();
    channel_2.getInfo();
    
	return 0;
}

/* OUTPUT : 

 Hey! I am Ng3w! Subscribe to my youtube Channel! 
**********************************
Channel Name : Ng3w
Channel Owner Name : UV
Subscriber count : 0
-------------1---------------
Video Name : Learn Python
Video Length : 1 hr
Video Author : Random Baba
----------------------------
-------------2---------------
Video Name : Learn C++
Video Length : 2 hrs
Video Author : Ng3w baba
----------------------------
-------------3---------------
Video Name : Learn C#
Video Length : 2 hrs
Video Author : Ng3w baba
----------------------------
**********************************
 Hey! I am Monkey Baba! Subscribe to my youtube Channel! 
**********************************
Channel Name : Monkey Baba
Channel Owner Name : Ng3w
Subscriber count : 0
-------------1---------------
Video Name : Learn how to Clean Code
Video Length : 3 hrs
Video Author : New Baba
----------------------------
-------------2---------------
Video Name : Learn Git/Github
Video Length : 1 hrs
Video Author : N Baba
----------------------------
**********************************
*/
