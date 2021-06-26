#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int mem[30001][501];
bool mem_if[30001][501];

int max_points(int pins[], int num_left, int num_balls_left, int n, int k, int w) {

if (mem_if[num_left][num_balls_left]==true)
    return mem[num_left][num_balls_left];

if (num_left>n || num_balls_left==0)
    return 0;

int total_add=0;

if (num_left>n-w+1) {
    
    for (int i=num_left-1; i<=n-1; i++)
    total_add=total_add+pins[i];

}
    

else {


    for (int i=num_left-1; i<=num_left+w-2; i++)
    total_add=total_add+pins[i];

}

int result=max((max_points(pins,num_left+w,num_balls_left-1,n,k,w)+total_add),(max_points(pins,num_left+1,num_balls_left,n,k,w)));
mem_if[num_left][num_balls_left]=true;
mem[num_left][num_balls_left]=result;
return result;

}

int main () {
 
int t;

cin>>t;

for (int i=1; i<=t; i++) {

memset(mem, 0, sizeof(mem));
memset(mem_if, 0, sizeof(mem_if));

int n;
int k;
int w;

cin>>n;
cin>>k;
cin>>w;

int *pins;

pins=new int[n];

for (int ii=0; ii<=n-1; ii++)
cin>>pins[ii];

int num_left=1;

int num_balls_left=k;

cout<<max_points(pins,num_left,num_balls_left,n,k,w)<<endl;

}
    
return 0;
}