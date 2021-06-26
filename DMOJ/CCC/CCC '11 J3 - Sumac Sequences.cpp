#include <iostream>
using namespace std;

int length(int t_1, int t_2) {

if (t_1<t_2)
  return 2;

return 1+length(t_2,t_1-t_2);

}

int main () {

int t_1;
int t_2;

cin>>t_1;
cin>>t_2;

cout<<length(t_1,t_2)<<endl;

return 0;

}