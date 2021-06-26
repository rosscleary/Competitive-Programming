#include <iostream>
using namespace std;
int main() {

int n;
float initial[100];

cin>>n;

for (int a=0; a<=n-1; a++)
cin>>initial[a];

int order;
int split;
int merge;
float percent;
float new_array[100];
float print[100];

while (order!=77){

cin>>order;

if (order==99){
    cin>>split;
    cin>>percent;
    
    for (int a=0; a<=split-2; a++)
    new_array[a]=initial[a];
    
    new_array[split-1]=initial[split-1]*(percent/100);
    new_array[split]=initial[split-1]*((100-percent)/100);
    
    for (int a=split+1; a<=n; a++)
    new_array[a]=initial[a-1];
    
    n=n+1;
}

if (order==88){
    cin>>merge;
    
    for (int a=0; a<=merge-2; a++)
    new_array[a]=initial[a];
    
    new_array[merge-1]=initial[merge-1]+initial[merge];
 
    for (int a=merge; a<=n-2; a++)
    new_array[a]=initial[a+1];   
    
    n=n-1; 
}

for (int a=0; a<=n-1; a++)
print[a]=initial[a];

for (int a=0; a<=n; a++)
initial[a]=0;

for (int a=0; a<=n-1; a++)
initial[a]=new_array[a];

for (int a=0; a<=n-1; a++)
new_array[a]=0;

}

for (int a=0; a<=n-1; a++)
cout<<print[a]<<" ";

return 0;
}