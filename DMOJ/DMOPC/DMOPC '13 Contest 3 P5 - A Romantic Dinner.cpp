#include <iostream>
#include <algorithm>
using namespace std;

int mem[151][301][101];
bool mem_if[151][301][101];

int max_value(int r, int values[], int times[], int units[], int num, int time_left, int units_left) {

if (mem_if[num][time_left][units_left]==true)
    return mem[num][time_left][units_left];

if (num>r || time_left==0 || units_left==0)
    return 0;
  
int result;

if (times[num-1]>time_left || units[num-1]>units_left)
    result=max_value(r,values,times,units,num+1,time_left,units_left);

else
 result=max(max_value(r,values,times,units,num+1,time_left-times[num-1],units_left-units[num-1])+values[num-1],max_value(r,values,times,units,num+1,time_left,units_left));

mem_if[num][time_left][units_left]=true;
mem[num][time_left][units_left]=result;
return result;

}

int main () {

int m;
int u;
int r;    
    
cin>>m;
cin>>u;
cin>>r;

int *values;
int *times;
int *units;

values=new int[r];
times=new int[r];
units=new int[r];

for (int i=0; i<=r-1; i++){
cin>>values[i];
cin>>times[i];
cin>>units[i];
}

int num=1;
int time_left=m;
int units_left=u;
    
cout<<max_value(r,values,times,units,num,time_left,units_left)<<endl;
    
return 0;
}