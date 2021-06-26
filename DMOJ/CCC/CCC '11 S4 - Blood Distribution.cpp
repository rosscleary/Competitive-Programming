#include <iostream>
using namespace std;
int main () {
    
unsigned long long int amo[8];
unsigned long long int pat[8];
long long int left[8];
int take[8][7]={{8,8,8,8,8,8,8},{0,8,8,8,8,8,8},{0,8,8,8,8,8,8},{2,1,0,8,8,8,8},{0,8,8,8,8,8,8},{4,1,0,8,8,8,8},{4,2,0,8,8,8,8},{6,5,3,4,2,1,0}};

for (int a=0; a<=7; a++)
cin>>amo[a];

for (int a=0; a<=7; a++)
cin>>pat[a];

for (int a=0; a<=7; a++)
left[a]=amo[a]-pat[a];

for (int a=0; a<=7; a++){
if (left[a]<0){
int need=-1*left[a];
int b=0;
while (need!=0 && take[a][b]!=8 && b<=6){
if (left[take[a][b]]>0){

if (need-left[take[a][b]]>=0){
need=need-left[take[a][b]];
left[take[a][b]]=0;
}

else{
left[take[a][b]]=left[take[a][b]]-need;
need=0;
}

}

b=b+1;
left[a]=-1*need;
}
       
}

}

long long int pat_sum=0;
for (int a=0; a<=7; a++)
pat_sum=pat_sum+pat[a];

long long int pat_counter=pat_sum;
for (int a=0; a<=7; a++){
if (left[a]<0)
    pat_counter=pat_counter+left[a];
}

cout<<pat_counter<<endl;

return 0;
}