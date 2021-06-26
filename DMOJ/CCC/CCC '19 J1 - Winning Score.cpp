#include <iostream>
using namespace std;
int main() {

int a_3;
int a_2;
int a_1;
int b_3;
int b_2;
int b_1;

cin>>a_3;
cin>>a_2;
cin>>a_1;
cin>>b_3;
cin>>b_2;
cin>>b_1;

if (((a_3*3)+(a_2*2)+(a_1))>((b_3*3)+(b_2*2)+(b_1)))
	cout<<"A"<<endl;

if (((a_3*3)+(a_2*2)+(a_1))<((b_3*3)+(b_2*2)+(b_1)))
	cout<<"B"<<endl;

if (((a_3*3)+(a_2*2)+(a_1))==((b_3*3)+(b_2*2)+(b_1)))
	cout<<"T"<<endl;

return 0;
}