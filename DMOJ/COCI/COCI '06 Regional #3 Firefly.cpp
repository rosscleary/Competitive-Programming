#include <iostream>
#include <algorithm>
using namespace std;
int main () {

int length;    
int height;

cin>>length;
cin>>height;

int h_at_l;

int *obstacles_at_h;
int *difference_array;

obstacles_at_h=new int[height+1];
difference_array=new int[height+2];

for (int i=0; i<=length-1; i++) {
cin>>h_at_l;

if (i%2==0) {
    
difference_array[1]=difference_array[1]+1;
difference_array[h_at_l+1]=difference_array[h_at_l+1]-1;

}
    

else {
    
difference_array[height-h_at_l+1]=difference_array[height-h_at_l+1]+1;
difference_array[height+1]=difference_array[height+1]-1;
    
}
    
}

for (int i = 0; i<=height; i++) { 

if (i==0) 
    obstacles_at_h[i]=difference_array[i]; 
  
else
    obstacles_at_h[i]=difference_array[i]+obstacles_at_h[i-1];

}

int smallest=length+1;

for (int i=1; i<=height; i++) {
    
if (obstacles_at_h[i]<smallest)
    smallest=obstacles_at_h[i]; 
    
}
 
int best_counter=0;

for (int i=1; i<=height; i++) {
    
if (obstacles_at_h[i]==smallest)
    best_counter=best_counter+1;
    
}   

cout<<smallest<<" "<<best_counter<<endl; 
    
return 0;
}