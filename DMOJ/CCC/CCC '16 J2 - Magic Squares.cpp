#include <iostream>
using namespace std;
int main () {
    
int square[4][4];
int sums[8];

for (int a=0; a<=3; a++){

    for (int b=0; b<=3; b++)
    cin>>square[a][b];
}

for (int a=0; a<=3; a++){
int sum=0;

    for (int b=0; b<=3; b++)
    sum=sum+square[a][b];

sums[a]=sum;
}

int c=5;
for (int a=0; a<=3; a++){
int sum=0;

    for (int b=0; b<=3; b++)
    sum=sum+square[b][a];

sums[c-1]=sum;
c=c+1;
}

if (sums[0]==sums[1] && sums[1]==sums[2] && sums[3]==sums[4] && sums[5])
    cout<<"magic"<<endl;
else
    cout<<"not magic"<<endl;
    
return 0;
}