#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    
int q;
int n;
int *count_1;
int *count_2;

cin>>q;
cin>>n;

count_1=new int[n];
count_2=new int[n];

for (int a=0; a<=n-1; a++)
cin>>count_1[a];

for (int a=0; a<=n-1; a++)
cin>>count_2[a];

sort(count_1,count_1+n);
sort(count_2,count_2+n);

if (q==1){
int speed=0;
    for (int a=0; a<=n-1; a++){
    if (count_1[a]>count_2[a])
        speed=speed+count_1[a];
    else
        speed=speed+count_2[a];
    }
    
cout<<speed<<endl;
}

if (q==2){
int speed=0;
    if (n%2==0){
        for (int a=n-1; a>=(n/2); a--){
        if (count_1[a]>count_2[n-a-1])
            speed=speed+count_1[a];
        else
            speed=speed+count_2[n-a-1];
            
        if (count_2[a]>count_1[n-a-1])
            speed=speed+count_2[a];
        else
            speed=speed+count_1[n-a-1];
        }
    }
    else{
        for (int a=n-1; a>=(n/2)+1; a--){
        if (count_1[a]>count_2[n-a-1])
            speed=speed+count_1[a];
        else
            speed=speed+count_2[n-a-1];
            
        if (count_2[a]>count_1[n-a-1])
            speed=speed+count_2[a];
        else
            speed=speed+count_1[n-a-1];
        }
        
        if (count_1[n/2]>count_2[n/2])
            speed=speed+count_1[n/2];
        else
            speed=speed+count_2[n/2];
    }
    
cout<<speed<<endl;
}



return 0;
}