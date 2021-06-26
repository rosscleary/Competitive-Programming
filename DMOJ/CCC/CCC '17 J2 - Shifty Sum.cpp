#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main () {

int n,k;

cin>>n>>k;

int number=n;
int sum=n;

for (int i=1; i<=k; i++) {
  number*=10;
  sum+=number;
}

cout<<sum<<endl;

return 0;

}