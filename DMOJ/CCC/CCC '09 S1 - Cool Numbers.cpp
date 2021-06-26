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

int start,end;
cin>>start>>end;

int works_counter=0;

for (int i=1; pow(i,6)<=end; i++) {
  if (pow(i,6)>=start) {
    works_counter++;
  }
}

cout<<works_counter<<endl;

return 0;

}