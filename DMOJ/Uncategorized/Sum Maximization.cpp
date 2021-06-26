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
using namespace std;

string n,m;
int str_length;

int max_digit_sum(int);

int main () {

  int q;
  cin>>q;

  while (q--) {
    cin>>n>>m;
    int length_difference=m.length()-n.length();
    for (int i=1; i<=length_difference; i++) {
      n.insert(0,"0");
    }
    str_length=m.length();
    cout<<max_digit_sum(0)<<endl;
  }

  return 0;

}

int max_digit_sum(int current_digit) {

  if (current_digit==str_length-1) {
    return m[current_digit]-'0';
  }
  if (n[current_digit]-'0'==m[current_digit]-'0') {
    return n[current_digit]-'0'+max_digit_sum(current_digit+1);
  }
  return max(((m[current_digit]-'0')-1)+(9*(str_length-current_digit-1)),m[current_digit]-'0'+max_digit_sum(current_digit+1));

}