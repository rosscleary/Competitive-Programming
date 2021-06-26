#include <iostream>
#include <cmath>
using namespace std;
int main () {

int n;

cin>>n;

string number;

int round_up_counter=0;
int round_down_counter=0;

for (int i=1; i<=n; i++) {

cin>>number;

int dot_spot=number.find('.');

if (dot_spot>-1 && dot_spot<100) {

if (number[number.find('.')+1]-'0'<5)
  round_down_counter=round_down_counter+1;
else
  round_up_counter=round_up_counter+1;

}

else
  round_down_counter=round_down_counter+1;

}

cout<<round_up_counter<<endl;
cout<<round_down_counter<<endl;

return 0;

}