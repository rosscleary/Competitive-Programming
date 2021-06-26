#include <iostream>
using namespace std;
int main () {

int x;
int m;

cin>>x;
cin>>m;

bool works=false;

for (int i=x; i<=m*m; i=i+x) {

if (i%m==1) {
  cout<<i/x<<endl;
  works=true;
  break;
}

}

if (works==false)
  cout<<"No such integer exists."<<endl;

return 0;

}