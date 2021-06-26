#include <iostream>
#include <map>
using namespace std;
int main () {

long long int n;
long long int k;

cin>>n;
cin>>k;

map <long long int,long long int> frequency;

long long int type;

long long int outputs[100000];

long long int diff_types=0;

for (int i=0; i<=n-1; i++) {

cin>>type;

if (frequency.count(type)==0) {
  outputs[i]=0;
  frequency[type]=1;
  diff_types++;
}

else {
outputs[i]=frequency[type];
frequency[type]++;
}

}

for (int i=0; i<=n-1; i++)
cout<<outputs[i]<<endl;

cout<<diff_types<<endl;

return 0;

}