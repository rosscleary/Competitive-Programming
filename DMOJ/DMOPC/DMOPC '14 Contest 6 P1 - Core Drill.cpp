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
#include <cstdlib>
#include <ctime>

using namespace std;

#define ll long long

const ll mod=1000000007;
const string alph_l("abcdefghijklmnopqrstuvwxyz");
const string alph_c("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const string digits("0123456789");

int main ()

{

  double r,h;
  cin>>r>>h;

  cout<<setprecision(2)<<fixed<<(3.1415*(r*r)*h)/3<<endl;

  return 0;

}