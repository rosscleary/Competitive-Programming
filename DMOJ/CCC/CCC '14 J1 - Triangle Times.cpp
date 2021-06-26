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

int angle_1,angle_2,angle_3;
cin>>angle_1>>angle_2>>angle_3;

int sum=angle_1+angle_2+angle_3;

if (sum==180) {
  if (angle_1!=angle_2 && angle_2!=angle_3 && angle_1!=angle_3) {
    cout<<"Scalene"<<endl;
  }
  else {
    if (angle_1==angle_2 && angle_2==angle_3) {
      cout<<"Equilateral"<<endl;
    }
    else {
      cout<<"Isosceles"<<endl;
    }
  }
}
else {
  cout<<"Error"<<endl;
}

return 0;

}