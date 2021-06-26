#include <iostream>
#include <string>
using namespace std;
int main () {

string input;
int l;
int index;
int array[2][2] = {{1,2},{3,4}};
int row;
int col;
int temp;

cin>>input;

l=input.length();

for (index=0; index<=l-1; index++){

	if (input[index]=='V'){
		for (row=0; row<=1; row++){
		temp=array[row][0];
		array[row][0]=array[row][1];
		array[row][1]=temp;
		}
	}

	if (input[index]=='H'){
		for (col=0; col<=1; col++){
		temp=array[0][col];
		array[0][col]=array[1][col];
		array[1][col]=temp;
		}
	}
}

for (row=0; row<=1; row++){
	for (col=0; col<=1; col++)
	cout<<array[row][col]<<" ";
cout<<endl;
}

return 0;
}