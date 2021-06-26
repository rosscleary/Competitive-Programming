#include <iostream>
#include <algorithm>
using namespace std;

int mem[1000][1000];
int mem_if[1000][1000];

int max_sum(int heights[], int height_num, int last_height, int num_heights) {
    
if (mem_if[height_num][last_height])
    return mem[height_num][last_height];

if (height_num==num_heights+1)
    return 0;
    
if (heights[height_num-1]<=last_height)
    return max_sum(heights,height_num+1,last_height,num_heights);
    
int result=max((max_sum(heights,height_num+1,last_height,num_heights)),(max_sum(heights,height_num+1,heights[height_num-1],num_heights)+heights[height_num-1]));

mem_if[height_num][last_height]=true;
mem[height_num][last_height]=result;
return result;

}

int main () {
    
int num_heights;
int *heights;

cin>>num_heights;

heights=new int[num_heights];

for (int i=0; i<=num_heights-1; i++)
cin>>heights[i];

int last_height=0;
int height_num=1;

cout<<max_sum(heights,height_num,last_height,num_heights)<<endl;
    
return 0;
}