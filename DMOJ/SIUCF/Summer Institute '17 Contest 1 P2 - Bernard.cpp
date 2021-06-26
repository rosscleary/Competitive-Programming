#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int mem[100001];
bool mem_if[100001];

unsigned long long int max_delic(unsigned long long int delics[], int num_left, int n, int k) {
 
if (mem_if[num_left]==true)
    return mem[num_left];

if (num_left>n)
    return 0;

unsigned long long int result=max(max_delic(delics,num_left+k+1,n,k)+delics[num_left-1],max_delic(delics,num_left+1,n,k));
mem_if[num_left]=true;
mem[num_left]=result;
return result;

}

int main () {
    
int n;
int k;

cin>>n;
cin>>k;

unsigned long long int *delics;

delics=new unsigned long long int[n];

for (int i=0; i<=n-1; i++)
cin>>delics[i];

int num_left=1;

cout<<max_delic(delics,num_left,n,k)<<endl;
    
return 0;
}