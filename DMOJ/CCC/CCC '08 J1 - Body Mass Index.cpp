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

float height,weight;
cin>>weight>>height;

float bmi=weight/(height*height);

if (bmi>25.0) {
  cout<<"Overweight"<<endl;
}
else {
  if (bmi<18.5) {
    cout<<"Underweight"<<endl;
  }
  else {
    cout<<"Normal weight"<<endl;
  }
}
return 0;

}