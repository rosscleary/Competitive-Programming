#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    
long int a;
long int b;
long int *mot;
long int n;

cin>>a;
cin>>b;
cin>>n;

mot=new long int[n+14];

mot[0]=0;
mot[1]=990;
mot[2]=1010;
mot[3]=1970;
mot[4]=2030;
mot[5]=2940;
mot[6]=3060;
mot[7]=3930;
mot[8]=4060;
mot[9]=4970;
mot[10]=5030;
mot[11]=5990;
mot[12]=6010;
mot[13]=7000;

for (int a=14; a<=n+13; a++)
cin>>mot[a];

sort(mot,mot+(n+14));

long int *subs;

subs=new long int[n+14];

for (int c=0; c<=n+13; c++)
subs[c]=0;

subs[0]=1;

for (int c=1; c<=n+13; c++){
    for (int d=0; d<=c-1; d++){
    if (mot[c]-mot[d]>=a && mot[c]-mot[d]<=b)
        subs[c]=subs[c] + subs[d];
    }
}

cout<<subs[n+13]<<endl;

return 0;
}