#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    
int n;

cin>>n;

int *strengths;

strengths=new int[n];

for (int i=0; i<=n-1; i++)
cin>>strengths[i];

int note=strengths[0];

sort(strengths,strengths+n);

if (strengths[n-1]==note && strengths[n-2]!=note)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;
    
return 0;

}