#include <iostream>
using namespace std;
int main (){
 
int value[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
int num;
int *cases;
int bank;
int index;
int sum=0;
 
cin>>num;
 
cases = new int[num];
 
for (index=0; index<=num-1; index++)
cin>>cases[index];
 
cin>>bank;
 
for (index=0; index<=num-1; index++)
sum=sum+value[cases[index]];
 
if ((1691600-sum)/(10-num)>bank)
   	cout<<"no deal"<<endl;
else
   	cout<<"deal"<<endl;
 
return 0;
}