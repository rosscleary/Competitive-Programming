#include <iostream>
using namespace std;
int main () {
    
int n;

cin>>n;

int *nums;

nums=new int[n];

for (int i=0; i<=n-1; i++)
cin>>nums[i];

for (int i=0; i<=n-1; i++)
cout<<nums[i]<<" ";

cout<<endl;

for (int i=1; i<=n; i++) {

for (int ii=0; ii<=n-2; ii++) {
        
if (nums[ii]>nums[ii+1]) {

int temp=nums[ii];
nums[ii]=nums[ii+1];
nums[ii+1]=temp;

for (int iii=0; iii<=n-1; iii++)
cout<<nums[iii]<<" ";

cout<<endl;
    
}
              
}
    
} 
    
return 0;

}