#include<bits/stdc++.h>
using namespace std;

class Youtube{
    public:
    void aboutMe() {
        cout<<"\n Hey! Subscribe to my youtube Channel! ";
    }
};

class Student : public Youtube {
    public:
    void aboutMe() {
        cout<<"\n Hey! I am a Student ";
    }
};

int main() {
    Student * P = new Student();
    Student p;
    Youtube a;
    a.aboutMe();
    p.aboutMe();
    P->aboutMe();
    delete P;
	return 0;
}

/* OUTPUT 

 Hey! Subscribe to my youtube Channel! 
 Hey! I am a Student 
 Hey! I am a Student 
*/
