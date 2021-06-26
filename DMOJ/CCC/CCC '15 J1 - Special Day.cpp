#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main () {

int month,day;

cin>>month>>day;

if (month<2) {
  cout<<"Before"<<endl;
}
else {
  if (month>2) {
    cout<<"After"<<endl;
  }
  else {
    if (day<18) {
      cout<<"Before"<<endl;
    }
    else {
      if (day>18) {
        cout<<"After"<<endl;
      }
      else {
        cout<<"Special"<<endl;
      }
    }
  }
}

return 0;

}