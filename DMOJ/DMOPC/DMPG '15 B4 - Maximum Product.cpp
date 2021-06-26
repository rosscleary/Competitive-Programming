#include <iostream>
#include <algorithm>
using namespace std;
int main () { 

int n;
int *nums;
int pos=0;
int nil=0;
int neg=0;

cin>>n;

nums=new int[n];

for (int a=0; a<=n-1; a++)
cin>>nums[a];

for (int a=0; a<=n-1; a++){
if (nums[a]>0)
	pos=pos+1;
if (nums[a]==0)
	nil=nil+1;
if (nums[a]<0)
	neg=neg+1;
}

sort(nums,nums+n);

if (pos==0 && neg==0)
	cout<<"0"<<endl;

if (pos==0 && neg==1 && nil>0)
	cout<<"0"<<endl;

if (pos==0 && neg==1 && nil==0)
	cout<<nums[0]<<endl;

if (neg>1 && pos==0){
    
if (neg%2==0){
	int product=1;
	int a=0;
	while (nums[a]!=0){
	product=product*nums[a];
	a=a+1;
	}
	cout<<product<<endl;
}

else {
	int product=1;
	int a=0;
	while (nums[a]!=0){
	product=product*nums[a];
	a=a+1;
	}
	product=product/nums[n-1];
	cout<<product<<endl;
		
}

}

if (pos>0){
    
int product=1;
for (int a=0; a<=n-1; a++){
if (nums[a]>0)
product=product*nums[a];
}

if (neg%2==0){
	int a=0;
	while (nums[a]<0){
	product=product*nums[a];
	a=a+1;
	}
	cout<<product<<endl;
}


else {
	int a=0;
	while (nums[a]<0){
	product=product*nums[a];
	a=a+1;
	}
	product=product/nums[a-1];
	cout<<product<<endl;	
}

}

return 0;
}