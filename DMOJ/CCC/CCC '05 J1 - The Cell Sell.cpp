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

int day_time,evening_time,weekend_time;
cin>>day_time>>evening_time>>weekend_time;

float plan_a_cost=0.00;
float plan_b_cost=0.00;

if (day_time>100) {
  plan_a_cost+=(day_time-100)*0.25;
}

if (day_time>250) {
  plan_b_cost+=(day_time-250)*0.45;
}

plan_a_cost+=evening_time*0.15;
plan_b_cost+=evening_time*0.35;

plan_a_cost+=weekend_time*0.20;
plan_b_cost+=weekend_time*0.25;

std::cout<<std::fixed;
std::cout<<std::setprecision(2);

cout<<"Plan A costs "<<plan_a_cost<<endl;
cout<<"Plan B costs "<<plan_b_cost<<endl;

if (plan_a_cost<plan_b_cost) {
  cout<<"Plan A is cheapest."<<endl;
}
else {
  if (plan_a_cost>plan_b_cost) {
    cout<<"Plan B is cheapest."<<endl;
  }
  else {
    cout<<"Plan A and B are the same price."<<endl;
  }
}

return 0;

}