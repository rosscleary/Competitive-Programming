#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    
int n;
int *x;
int *y;
int x_p;
int y_p;

cin>>n;

x=new int[n];

y=new int[n];

for (int a=0; a<=n-1; a++){
cin>>x[a];
cin>>y[a];
}

sort(x,x+n);
sort(y,y+n);

if (n%2==1){
    x_p=x[(n-1)/2];
    y_p=y[(n-1)/2];
}
else{
    x_p=x[(n-1)/2+1];
    y_p=y[(n-1)/2+1];
}

long long int time=0;
for (int a=0; a<=n-1; a++){
if (x[a]-x_p>0)
    time=time+(x[a]-x_p);

else
    time=time+(x_p-x[a]);
    
if (y[a]-y_p>0)
    time=time+(y[a]-y_p);

else
    time=time+(y_p-y[a]);
}

cout<<time<<endl;

return 0;
}