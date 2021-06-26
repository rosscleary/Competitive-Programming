#include <iostream>
#include <string>
using namespace std;
int main () {

string *array;
int n;
int index;
int index_2;
int l;
int counter=1;

cin>>n;

array=new string[n];

for (index=0; index<=n-1; index++)
cin>>array[index];

for (index=0; index<=n-1; index++){
array[index]=array[index]+" ";
l=array[index].length();
counter=1;
	for (index_2=1; index_2<=l-1; index_2++){
	if (array[index][index_2]==array[index][index_2-1])
		counter=counter+1;
	else{
		cout<<counter<<" "<<array[index][index_2-1]<<" ";
		counter=1;}
	}

cout<<endl;
}

return 0;
}