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

int num_1,num_2,num_3;
cin>>num_1>>num_2>>num_3;

int answer=91+(num_1+(num_2*3)+num_3);

cout<<"The 1-3-sum is "<<answer<<endl;

return 0;

}