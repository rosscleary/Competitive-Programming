#include <iostream>
#include <string>
using namespace std;
int main () {
 
int n;
string *studs;
char *lett;
int big_counter=0;

cin>>n;

studs=new string[n];
lett=new char[n];

for (int a=0; a<=n-1; a++){
cin>>studs[a];
lett[a]=(studs[a])[0];
}

int b=0;
while (b<=n-1){
int on=1;
if (lett[b]==lett[b+1]){
    int counter=2;
    while (on==1){
    b=b+1;
    if (lett[b]==lett[b+1])
        counter=counter+1;
    else{
        on=0;
        big_counter=big_counter+((counter*(counter+1))/2);
        }
        
    }
}
else
    big_counter=big_counter+1;
b=b+1;
}

cout<<big_counter%1000000007<<endl;

return 0;
}