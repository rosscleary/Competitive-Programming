#include <iostream>
using namespace std;
int main () {

int j;
int counter=0;

cin>>j;

for (int a=j-1; a>=3; a--){
	for (int b=a-1; b>=2; b--){
		for (int c=b-1; c>=1; c--)
			counter=counter+1;
	}
}

cout<<counter<<endl;

return 0;
}