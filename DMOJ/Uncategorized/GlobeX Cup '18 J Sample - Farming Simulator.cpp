#include <iostream>
#include <algorithm>
using namespace std;
int main () {

int n;
int m;

cin>>n;
cin>>m;

int values[100000];

for (int i=0; i<=n-1; i++)
cin>>values[i];

if (n-m==0)
  cout<<"0"<<endl;

else {

sort(values,values+n);

unsigned long long int new_value=0;

for (int i=n-1; i>=m; i--)
new_value=new_value+values[i];

cout<<new_value<<endl;

}

return 0;

}