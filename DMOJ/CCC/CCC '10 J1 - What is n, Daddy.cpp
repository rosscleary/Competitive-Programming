#include <iostream>
using namespace std;
int main () {
int n;

cin>>n;

int counter=0;

for (int i=n/2; i>=0; i--) {
if (i<5 && n-i<5)
    counter=counter+1;
else {
    counter=counter+1;
    break;
}

}

cout<<counter<<endl;

return 0;
}