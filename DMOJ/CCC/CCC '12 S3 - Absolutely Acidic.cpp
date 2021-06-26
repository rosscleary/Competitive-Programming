#include <iostream>
#include <vector>
using namespace std;

int abs_diff(int x, int y) {

if (x>y)
  return x-y;
else
  return y-x;

}

int main () {

int n;

cin>>n;

int occured[2000001];
int frequency[2000001];
int occured_counter=0;

int input;

for (int i=1; i<=n; i++) {

cin>>input;

if (frequency[input]==0) {

  occured[occured_counter]=input;
  frequency[input]=1;
  occured_counter=occured_counter+1;

}

else
  frequency[input]=frequency[input]+1;  

}

int largest_1=0;

for (int i=0; i<=occured_counter-1; i++) {

if (frequency[occured[i]]>largest_1)
  largest_1=frequency[occured[i]];

}

vector <int> largest_1s;

for (int i=0; i<=occured_counter-1; i++) {

if (frequency[occured[i]]==largest_1)
  largest_1s.push_back(occured[i]);

}

if (largest_1s.size()>1) {

int largest_diff=0;

for (int i=0; i<=largest_1s.size()-2; i++) {

for (int ii=i+1; ii<=largest_1s.size()-1; ii++) {

if (abs_diff(largest_1s[i],largest_1s[ii])>largest_diff)
  largest_diff=abs_diff(largest_1s[i],largest_1s[ii]);

}

}

cout<<largest_diff<<endl;

}

else {

if (frequency[largest_1s[0]]==n)
  cout<<"0"<<endl;

else {

int largest_2=0;

for (int i=0; i<=occured_counter-1; i++) {

if (frequency[occured[i]]>largest_2 && occured[i]!=largest_1s[0])
  largest_2=frequency[occured[i]];

}

vector <int> largest_2s;

for (int i=0; i<=occured_counter-1; i++) {

if (frequency[occured[i]]==largest_2)
  largest_2s.push_back(occured[i]);

}

if (largest_2s.size()==1)
  cout<<abs_diff(largest_1s[0],largest_2s[0])<<endl;

else {

int largest_diff_2=0;

for (int i=0; i<=largest_2s.size()-1; i++) {

if (abs_diff(largest_1s[0],largest_2s[i])>largest_diff_2)
  largest_diff_2=abs_diff(largest_1s[0],largest_2s[i]);

}

cout<<largest_diff_2<<endl;

}

}

}

return 0;

}