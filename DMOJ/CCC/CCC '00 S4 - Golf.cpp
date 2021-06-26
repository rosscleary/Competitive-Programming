#include <iostream>
using namespace std;

int main () {
  
int total;
int club;
int *dist;

cin>>total;
cin>>club;

dist=new int[club];

for (int a=0; a<=club-1; a++)
cin>>dist[a];

int *subs;

subs=new int[total+1];

for (int a=0; a<=total; a++)
subs[a]=total+1;

subs[0]=0;
for (int a=1; a<=total; a++){
int on=0;
int smallest=total+1;

for (int b=0; b<=club-1; b++){
if (dist[b]==a){
    subs[a]=1;
    smallest=1;
    on=1;
}
}

if (on==0){
    for (int b=1; b<=a/2; b++){
    if (subs[b]+subs[a-b]<smallest)
        smallest=subs[b]+subs[a-b];
    }
}

subs[a]=smallest;
    
}   

int counter=0;
for (int a=0; a<=total; a++){
if (subs[a]==total+1)
    counter=counter+1;
}

if (subs[total]==total+1)
    cout<<"Roberta acknowledges defeat."<<endl;
else
    cout<<"Roberta wins in "<<subs[total]<<" strokes."<<endl;

return 0;
}