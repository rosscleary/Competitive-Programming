#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    
int n;
int *nums;

cin>>n;

nums=new int[n];

for (int a=0; a<=n-1; a++)

cin>>nums[a];

sort(nums,nums+n);

int smallest=10000000000000;

for (int a=0; a<=n-2; a++){
if (nums[a+1]-nums[a]<smallest)
    smallest=nums[a+1]-nums[a];
}

cout<<smallest<<endl;

return 0;
}