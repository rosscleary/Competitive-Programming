#include <iostream>
using namespace std;
int main () {

int n;

cin>>n;

char *student=new char[n];

char *answers=new char[n];

for (int i=0; i<=n-1; i++)
cin>>student[i];

for (int i=0; i<=n-1; i++)
cin>>answers[i];

int correct_counter=0;

for (int i=0; i<=n-1; i++) {

if (student[i]==answers[i])
  correct_counter=correct_counter+1;

}

cout<<correct_counter<<endl;

return 0;

}