#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
using namespace std;

int main () {

  int t;
  cin>>t;
  while (t--) {

    int n;
    cin>>n;
    vector<int> car_numbers;
    for (int i=1,car; i<=n; i++) {
      cin>>car;
      car_numbers.push_back(car);
    }
    vector<int> branch_cars;
    branch_cars.push_back(-1);
    int last_down=0;
    for (int i=1; i<=n; i++) {
      if (car_numbers[car_numbers.size()-1]==i) {
        car_numbers.erase(car_numbers.begin()+car_numbers.size()-1);
        last_down=i;
      }
      else {
        if (branch_cars[branch_cars.size()-1]==i) {
          branch_cars.erase(branch_cars.begin()+branch_cars.size()-1);
          last_down=i;
        }
        else {
          branch_cars.push_back(i);
        }
      }
    }

    if (last_down==n) {
      cout<<"Y"<<endl;
    }
    else {
      bool works=true;
      int current_car=last_down+1;
      for (int i=1; i<branch_cars.size(); i++) {
        if (branch_cars[i]!=last_down+1) {
          works=false;
          break;
        }
        last_down++;
      }
      if (works) {
        cout<<"Y"<<endl;
      }
      else {
        cout<<"N"<<endl;
      }
    }

  }

  return 0;

}