#include <iostream>
using namespace std;

bool arith_check(int sequence[10]) {

for (int i=2; i<=9; i++) {

if (sequence[i]-sequence[i-1]!=sequence[i-1]-sequence[i-2])
  return false;

}

return true;

}

bool geom_check(int sequence[10]) {

for (int i=0; i<=7; i++) {

if (sequence[i+1]*sequence[i+1]!=sequence[i]*sequence[i+2])
  return false;

}

return true;

}

int main () {

int n;

cin>>n;

for (int i=1; i<=n; i++) {

int sequence[10];

for (int ii=0; ii<=9; ii++)
cin>>sequence[ii];

int answer_arith=arith_check(sequence);
int answer_geom=geom_check(sequence);

if (answer_arith==true && answer_geom==true)
  cout<<"both"<<endl;

else {

if (answer_arith==false && answer_geom==false)
  cout<<"neither"<<endl;

else {

if (answer_arith==true)
  cout<<"arithmetic"<<endl;
else
  cout<<"geometric"<<endl;

}

}

}

}