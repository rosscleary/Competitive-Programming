#include <iostream>
using namespace std;
int main () {
 
int n;
int d;
int a;
int b;
int c;
int largest=0;
int *option;
int answer=0;
 
 
cin>>n>>d;
 
option = new int[n];
 
for (a=0; a<=n-1; a++){
cin>>option[a];
}
 
for (b=0; b<=n-1; b++){
if (d%(option[b])==0){
   	answer=option[b];}
 
if (largest<answer){
   	largest=answer;}
}
 
if (answer==0)
   	cout<<"This is not the best time for a trip."<<endl;
else
   	if (d/largest<0)
   	cout<<-(d/largest)<<endl;
   	else
   	cout<<d/largest<<endl;
 
return 0;
}