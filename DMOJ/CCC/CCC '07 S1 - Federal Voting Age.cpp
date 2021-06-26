#include <iostream>
using namespace std;
int main () {

int n;

cin>>n;

int y;
int m;
int d;

int age;

for (int a=1; a<=n; a++){
cin>>y;
cin>>m;
cin>>d;

if ((m<2) || (m==2 && d<=27))
	age=2007-y;
else
	age=2007-y-1;

if (age>=18)
	cout<<"Yes"<<endl;
else
	cout<<"No"<<endl;
}

return 0;
}