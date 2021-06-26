#include <iostream>
using namespace std;

int a;
int b;
int c;
int d;
int e;
int n;

unsigned long long int value(int n) {

if (n==0)
  return e;

return (a*value(n/b) + c*value(n/d))%1000000007;

}

int main () {

cin>>a;
cin>>b;
cin>>c;
cin>>d;
cin>>e;
cin>>n;

cout<<value(n)<<endl;

return 0;

}