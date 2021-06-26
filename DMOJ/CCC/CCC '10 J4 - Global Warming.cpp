#include <iostream>
#include <vector>
using namespace std;
int main () {
    
int on=1;

while (on==1) {
  
int length;

cin>>length;

if (length==0) {
    on=0;
    break;
}

int *temps;

temps=new int[length];

for (int i=0; i<=length-1; i++)
cin>>temps[i];

int *diffs;

diffs=new int[length-1];

for (int i=1; i<=length-1; i++)
diffs[i-1]=temps[i]-temps[i-1];

vector <int> cycle;

cycle.push_back(diffs[0]);

int cycle_counter=0;

int best_cycle=1;

int i=0;

while (i<=length-2) {

if (diffs[i]==cycle[cycle_counter]) {
    
    if (cycle_counter==best_cycle-1)
        cycle_counter=0;
        
    else
        cycle_counter=cycle_counter+1;
        
i=i+1;
    
}
    
else {
    
cycle.push_back(diffs[best_cycle]);
best_cycle=best_cycle+1;
i=best_cycle;  
    
}    
    
}

if (length==1)
    cout<<"0"<<endl;
else
    cout<<best_cycle<<endl;    
    
}    
    
return 0;
}