#include <iostream>
#include <algorithm>
using namespace std;

int mem[1001][1001];
int mem_if[1001][1001]={false};

int max_prince_sat(int cage_num, int time_left, int cage_times[], int cage_values[]) {

if (mem_if[cage_num][time_left]==true)
    return mem[cage_num][time_left];

if (time_left==0 || cage_num==0)
    return 0;
    
int result;
    
if (cage_times[cage_num-1]>time_left) {
    result=max_prince_sat(cage_num-1,time_left,cage_times,cage_values);
    mem_if[cage_num][time_left]=true;
    mem[cage_num][time_left]=result;
    return result;
}
    
result=max((max_prince_sat(cage_num-1,time_left-cage_times[cage_num-1],cage_times,cage_values)+cage_values[cage_num-1]),(max_prince_sat(cage_num-1,time_left,cage_times,cage_values)));
mem_if[cage_num][time_left]=true;
mem[cage_num][time_left]=result;
return result;

}

int main () {

int cage_num;
int time_left;
int *cage_times;
int *cage_values;

cin>>cage_num;
cin>>time_left;

cage_times=new int[cage_num];
cage_values=new int[cage_num];

for (int i=0; i<=cage_num-1; i++) {
cin>>cage_values[i];
cin>>cage_times[i];
}

cout<<max_prince_sat(cage_num,time_left,cage_times,cage_values)<<endl;

return 0;
}