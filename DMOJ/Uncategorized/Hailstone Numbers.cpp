#include <iostream>
using namespace std;

long long int num_moves(long long int num) {

if (num==1)
  return 0;

if (num%2==0)
  return 1+num_moves(num/2);
else
  return 1+num_moves(num*3+1);

}

int main () {

long long int n;

cin>>n;

cout<<num_moves(n)<<endl;

return 0;

}