#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  string a,b;
  int s;
  cin>>a>>b>>s;
  vector < vector <long long> > dp_b(136,vector <long long> (2));
  dp_b[0][0]=1;
  for (int digit_position=0; digit_position<b.length(); digit_position++) {
    vector < vector <long long> > new_dp(136,vector <long long> (2));
    for (int sum=0; sum<=9*digit_position; sum++) {
      for (int new_digit=0; new_digit<=b[digit_position]-'0'; new_digit++) {
        if (new_digit!=b[digit_position]-'0') {
          new_dp[sum+new_digit][1]+=dp_b[sum][0];
        }
        else {
          new_dp[sum+new_digit][0]+=dp_b[sum][0];
        }
      }
      for (int new_digit=0; new_digit<=9; new_digit++) {
        new_dp[sum+new_digit][1]+=dp_b[sum][1];
      }
    }
    dp_b=new_dp;
  }
  vector < vector <long long> > dp_a(136,vector <long long> (2));
  dp_a[0][0]=1;
  for (int digit_position=0; digit_position<a.length(); digit_position++) {
    vector < vector <long long> > new_dp(136,vector <long long> (2));
    for (int sum=0; sum<=9*digit_position; sum++) {
      for (int new_digit=0; new_digit<=a[digit_position]-'0'; new_digit++) {
        if (new_digit!=a[digit_position]-'0') {
          new_dp[sum+new_digit][1]+=dp_a[sum][0];
        }
        else {
          new_dp[sum+new_digit][0]+=dp_a[sum][0];
        }
      }
      for (int new_digit=0; new_digit<=9; new_digit++) {
        new_dp[sum+new_digit][1]+=dp_a[sum][1];
      }
    }
    dp_a=new_dp;
  }
  long long num_numbers=(dp_b[s][1]+dp_b[s][0])-dp_a[s][1];
  string real_a("");
  for (int i=1; i<=b.length()-a.length(); i++) {
    real_a+='0';
  }
  for (int i=0; i<a.length(); i++) {
    real_a+=a[i];
  }
  vector <int> smallest_digits;
  int smallest_sum=0;
  for (int i=0; i<=real_a.length()-1; i++) {
    smallest_digits.push_back(real_a[i]-'0');
    smallest_sum+=real_a[i]-'0';
  }
  int new_sum=smallest_sum;
  int i=smallest_digits.size()-1;
  while (new_sum<s) {
    int original_i=smallest_digits[i];
    smallest_digits[i]=min(9,smallest_digits[i]+(s-new_sum));
    new_sum+=smallest_digits[i]-original_i;
    i--;
  }
  long long smallest_number=0;
  int start_index;
  for (int i=0; i<=smallest_digits.size()-1; i++) {
    if (smallest_digits[i]!=0) {
      start_index=i;
      break;
    }
  }
  int pow_10_counter=0;
  for (int i=smallest_digits.size()-1; i>=start_index; i--) {
    smallest_number+=pow(10,pow_10_counter)*smallest_digits[i];
    pow_10_counter++;
  }
  cout<<num_numbers<<endl;
  cout<<smallest_number<<endl;
}