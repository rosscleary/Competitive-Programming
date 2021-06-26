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

int n;
cin>>n;

int curr_num=n;

int cost=0;

while (curr_num>1) {
  for (int i=ceil(curr_num/2); i<=curr_num-1; i++) {
    if (i%(curr_num-i)==0) {
      cost+=i/(curr_num-i);
      curr_num=i;
      break;
    }
  }
}

cout<<cost<<endl;

return 0;

}