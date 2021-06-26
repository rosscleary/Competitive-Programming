#include <iostream>
using namespace std;
int main () {

int start;
int num_days;

cin>>start>>num_days;

cout<<"Sun "<<"Mon "<<"Tue "<<"Wed "<<"Thr "<<"Fri "<<"Sat"<<endl;

for (int i=1; i<=start*4-2; i++) {
  cout<<" ";
}

for (int i=1; i<=num_days; i++) {
  if ((i+(start-1))%7==0) {
    if (i>=9) {
      if (i==num_days) {
        cout<<i<<endl;
      }
      else {
      cout<<i<<endl<<" ";
      }
    }
    else {
      cout<<i<<endl<<"  ";
    }
  }
  else {
    if (i>=9) {
      if (i==num_days) {
        cout<<i<<endl;
      }
      else {
        cout<<i<<"  ";
      }
    }
    else {
      cout<<i<<"   ";
    }
  }
}

return 0;

}