#include <iostream>
using namespace std;
int main () {
 
int quantity;
int *numbers;
int *sum;
int a;
int b=0;
int c;
int counter=1;
 
cin>>quantity;
 
numbers = new int[quantity*2];
sum = new int[quantity];
 
 
for (a=0; a<=(quantity*2)-1; a++){
cin>>numbers[a];
 
if (counter%2==0){
   	sum[b]=numbers[a] + numbers[a-1];
   	b=b+1;}
 
counter=counter+1;
}
 
for (c=0; c<=quantity-1; c++)
cout<<sum[c]<<endl;
 
return 0;
}