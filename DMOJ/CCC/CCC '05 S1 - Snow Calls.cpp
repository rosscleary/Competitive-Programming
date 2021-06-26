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
#define ll long long
using namespace std;

const string digits("0123456789");
const string str_1("ABC");
const string str_2("DEF");
const string str_3("GHI");
const string str_4("JKL");
const string str_5("MNO");
const string str_6("PQRS");
const string str_7("TUV");
const string str_8("WXYZ");

char new_char (char c) {

  if (digits.find(c)!=-1) {
    return c;
  }

  if (str_1.find(c)!=-1) {
    return '2';
  }
  if (str_2.find(c)!=-1) {
    return '3';
  }
  if (str_3.find(c)!=-1) {
    return '4';
  }
  if (str_4.find(c)!=-1) {
    return '5';
  }
  if (str_5.find(c)!=-1) {
    return '6';
  }
  if (str_6.find(c)!=-1) {
    return '7';
  }
  if (str_7.find(c)!=-1) {
    return '8';
  }
  return '9';
  
}

int main () {

  int t;
  scanf("%d",&t);

  while (t--) {

    string phone_num;
    cin>>phone_num;

    int num_counter=0;
    for (int i=0; i<phone_num.length(); i++) {
      if ((num_counter==3 || num_counter==6) && phone_num[i-1]!='-') {
        printf("-");
      }
      if (phone_num[i]!='-' && num_counter<10) {
        num_counter++;
        cout<<new_char(phone_num[i]);
      }
    }

    printf("\n");

  }

  return 0;

}