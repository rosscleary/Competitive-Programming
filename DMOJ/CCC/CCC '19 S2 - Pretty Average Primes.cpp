#include <iostream>
#include <cmath>
using namespace std;
  
bool prime(int x) {

for (int i=2; i<=sqrt(x); i++) {
if (x%i==0)  
    return false;
}

return true;
 
}

int main () {

int t;
int n;

cin>>t;

for (int i=1; i<=t; i++) {

cin>>n;

int on=1;

int counter_1;
int counter_2;

if (n%2==0) {
    counter_1=n-1;
    counter_2=n+1;
}

else {
    counter_1=n;
    counter_2=n;
} 

while (on==1) {

bool ans_1=prime(counter_1);

bool ans_2=prime(counter_2);
    
if (ans_1==true && ans_2==true) {
    cout<<counter_1<<" "<<counter_2<<endl;
    on=0;
}
    
counter_1=counter_1-2;

counter_2=counter_2+2;

}
    
}   
    
return 0;

}