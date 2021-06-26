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

int burger,drink,side,dessert;
cin>>burger>>side>>drink>>dessert;

int calorie_count=0;

if (burger!=4) {
  if (burger==1) {
    calorie_count+=461;
  }
  else {
    if (burger==2) {
      calorie_count+=431;
    }
    else {
        calorie_count+=420;
    }
  }
}

if (drink!=4) {
  if (drink==1) {
    calorie_count+=130;
  }
  else {
    if (drink==2) {
      calorie_count+=160;
    }
    else {
        calorie_count+=118;
    }
  }
}

if (side!=4) {
  if (side==1) {
    calorie_count+=100;
  }
  else {
    if (side==2) {
      calorie_count+=57;
    }
    else {
        calorie_count+=70;
    }
  }
}

if (dessert!=4){
  if (dessert==1) {
    calorie_count+=167;
  }
  else {
    if (dessert==2) {
      calorie_count+=266;
    }
    else {
        calorie_count+=75;
    }
  }
}

cout<<"Your total Calorie count is "<<calorie_count<<"."<<endl;
return 0;

}