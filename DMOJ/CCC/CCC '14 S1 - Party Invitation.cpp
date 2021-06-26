#include <iostream>
using namespace std;
int main (){

int k;
int m;
int *iPtr;
int index;
int counter;
int *remPtr;
int a;
int time;
int *oldPtr;
int b;

cin>>k;
cin>>m;

int n=k;

iPtr = new int[m];
remPtr = new int[k];


for (index=0; index<=m-1; index++)
cin>>iPtr[index];

for (index=0; index<=k-1; index++)
remPtr[index]=index+1;


for (counter=1; counter<=m; counter++){
oldPtr = new int[n];

    for (index=0; index<=n-1; index++)		
    oldPtr[index]=remPtr[index];

time = n - (n%iPtr[counter-1]);
remPtr = new int[time];
a=0;
b=n;

	for (index=1; index<=b; index++){
	if (index%iPtr[counter-1]!=0){
		remPtr[a]=oldPtr[index-1];
		a=a+1;}
	if (index%iPtr[counter-1]==0){
	    n=n-1;}
	}
    
}

for (index=0; index<=n-1; index++)
cout<<remPtr[index]<<endl;

return 0;
}