#include <iostream>
using namespace std;
int main () {

int n;
int m;
int a;
int b;
int c;

cin>>n;
cin>>m;
cin>>a;
cin>>b;
cin>>c;

bool doeswin[1001];

for (int i=1; i<=n; i++)
cin>>doeswin[i];

long long int rating=m;

int opponent;

for (int i=1; i<=c; i++) {

cin>>opponent;

if (doeswin[opponent])
  rating+=a;

else
  rating-=b;

}

cout<<rating<<endl;

return 0;

}