#include <iostream>
#include <algorithm>
using namespace std;

int mem[1501][1501];

int min_time(int n, int **times, int n_counter, int last_left, int last_right) {

if (mem[last_left][last_right]!=0)
    return mem[last_left][last_right];

if (n_counter==0)
    return 0;
    
if (n_counter==1)
    return (times[n_counter][last_right]+times[last_left][n_counter]);

else {

int result_1=min_time(n,times,n_counter-1,n_counter,last_right)+times[last_left][n_counter];

int result_2=min_time(n,times,n_counter-1,last_left,n_counter)+times[n_counter][last_right];

if (result_1<result_2) {
    mem[last_left][last_right]=result_1;
    return result_1;
}

else {
    mem[last_left][last_right]=result_2;
    return result_2;
}
    
}

}

int main () {
    
int n;

cin>>n;

int **times;

times=new int*[n+1];

for (int i=0; i<=n; i++)
times[i]=new int[n+1];

for (int i=1; i<=n; i++) {
    
    for (int ii=1; ii<=n; ii++)
    cin>>times[i][ii];
    
}

int n_counter=n;
int last_left=0;
int last_right=0;

cout<<min_time(n,times,n_counter,last_left,last_right)<<endl;
     
return 0;
}