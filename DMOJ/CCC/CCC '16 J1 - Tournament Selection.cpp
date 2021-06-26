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

char win_lose;

int win_counter=0;

for (int i=1; i<=6; i++) {
  cin>>win_lose;
  if (win_lose=='W') {
    win_counter++;
  }
}

if (win_counter>=5) {
  cout<<"1"<<endl;
}
else {
  if (win_counter>=3) {
    cout<<"2"<<endl;
  }
  else {
    if (win_counter>=1) {
      cout<<"3"<<endl;
    }
    else {
      cout<<"-1"<<endl;
    }
  }
}

return 0;

}