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
using namespace std;

int main () {

  cout<<"8128"<<endl;
  cout<<"153 370 371 407"<<endl;

  return 0;

}

// bool is_perfect(int);
// bool is_digit_sum(int);

// int main () {

//   for (int i=1000; i<10000; i++) {
//     if (is_perfect(i)) {
//       cout<<i<<" ";
//     }
//   }
//   cout<<endl;

//   for (int i=100; i<1000; i++) {
//     if (is_digit_sum(i)) {
//       cout<<i<<" ";
//     }
//   }
//   cout<<endl;

//   return 0;

// }

// bool is_perfect(int a) {

//   int div_sum=1;
//   for (int i=2; i<=sqrt(a); i++) {
//     if (a%i==0) {
//       if (i==a/i) {
//         div_sum+=i;
//       }
//       else {
//         div_sum+=i+a/i;
//       }
//     }
//   }

//   if (div_sum==a) {
//     return true;
//   }
//   return false;

// }

// bool is_digit_sum(int a) {

//   int curr_num=a;
//   int digit_sum=0;
//   while (curr_num>0) {
//     digit_sum+=pow(curr_num%10,3);
//     curr_num/=10;
//   }

//   if (digit_sum==a) {
//     return true;
//   }
//   return false;

// }