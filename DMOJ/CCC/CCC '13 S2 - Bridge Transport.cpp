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

int w,n;
cin>>w>>n;

int weights[100001];

for (int i=1; i<=n; i++) {
  cin>>weights[i];
}

int start_4_sum=0;

for (int i=1; i<=4; i++) {
  start_4_sum+=weights[i];
}

if (start_4_sum>w) {
  int curr_sum=0;
  for (int i=1; i<=4; i++) {
    curr_sum+=weights[i];
    if (curr_sum>w) {
      cout<<i-1<<endl;
      break;
    }
  }
}
else {
  int curr_sum=start_4_sum;
  bool all_can=true;
  for (int i=5; i<=n; i++) {
    curr_sum-=weights[i-4];
    curr_sum+=weights[i];
    if (curr_sum>w) {
      cout<<i-1<<endl;
      all_can=false;
      break;
    }
  }
  if (all_can) {
    cout<<n<<endl;
  }
}

return 0;

}