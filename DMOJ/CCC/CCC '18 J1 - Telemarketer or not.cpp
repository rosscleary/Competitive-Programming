#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main () {

int num_1,num_2,num_3,num_4;
cin>>num_1>>num_2>>num_3>>num_4;

if ((num_1==8 || num_1==9) && (num_4==8 || num_4==9) && (num_2==num_3)) {
  cout<<"ignore"<<endl;
}
else {
  cout<<"answer"<<endl;
}

return 0;

}