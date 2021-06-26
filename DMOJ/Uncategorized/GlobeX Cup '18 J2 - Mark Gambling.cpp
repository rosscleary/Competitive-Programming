#include <iostream>
using namespace std;
int main () {

int n;
cin>>n;

float marks[100000];

float sum;

for (int i=0; i<=n-1; i++) {

cin>>marks[i];

sum=sum+marks[i];

}

float average=sum/n;

int should_counter=0;

for (int i=0; i<=n-1; i++) {

if (marks[i]>average)
  should_counter=should_counter+1;

}

if (should_counter>(n/2))
  cout<<"Winnie should take the risk"<<endl;
else
  cout<<"That's too risky"<<endl;

return 0;

}