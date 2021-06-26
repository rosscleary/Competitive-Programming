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

int nums[3];

cin>>nums[0];
cin>>nums[1];
cin>>nums[2];

sort(nums,nums+3);

int answer=max(nums[1]-nums[0],nums[2]-nums[1])-1;

cout<<answer<<endl;

return 0;

}