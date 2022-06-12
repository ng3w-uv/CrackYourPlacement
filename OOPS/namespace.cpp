#include<bits/stdc++.h>
// using namespace std;
using std::string;
using std::cout;
using std::endl;

namespace namespace1 {
int age = 25;
string name = "Yuvraj";
}
namespace namespace2 {
int age = 35;
string name = "Raju";
}

int main() {
    cout << namespace1::name << "'s age is " << namespace1::age << endl;
    cout << namespace2::name << "'s age is " << namespace2::age << endl;
    return 0;
}

/*OUTPUT
Yuvraj's age is 25
Raju's age is 35
*/
