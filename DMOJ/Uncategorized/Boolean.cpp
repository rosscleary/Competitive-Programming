#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;
int main () {

string word;

int not_counter=0;

while (word!="True" || word!="False") {
  cin>>word;
  if (word=="True" || word=="False") {
    break;
  }
  else {
    not_counter++;
  }
}

if (not_counter%2==0) {
  cout<<word<<endl;
}
else {
  if (word=="True") {
    cout<<"False"<<endl;
  }
  else {
    cout<<"True"<<endl;
  }
}

return 0;

}