#include <iostream>
using namespace std;
int main () {
    
int p;
int c;
int v;

cin>>p;
cin>>c;
cin>>v;

int ans_p;
int ans_c;
int ans_v;

if (p%3==0)
    ans_p=p/3;
else
    ans_p=p/3+1;
    
if (c%3==0)
    ans_c=c/3;
else
    ans_c=c/3+1;
    
if (v%3==0)
    ans_v=v/3;
else
    ans_v=v/3+1;

cout<<ans_p+ans_c+ans_v<<endl;
    
return 0;

}