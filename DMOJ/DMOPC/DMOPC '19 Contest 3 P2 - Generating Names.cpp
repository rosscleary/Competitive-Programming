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

const string alph("abcdefghijklmnopqrstuvwxyz");

map<vector<char>,bool> str_counted;

ll factorial (int a) {

  ll factorial_sub=1;
  for (int i=2; i<=a; i++) {
    factorial_sub*=i;
  }

  return factorial_sub;

}

ll perm_counter (string str) {

  vector<char> vec_str;
  for (int i=0; i<str.length(); i++) {
    vec_str.push_back(str[i]);
  }

  sort(vec_str.begin(),vec_str.end());

  if (str_counted[vec_str]) {
    return 0;
  }

  ll perm_counter_sub=1;
  int factorial_value=str.length();
  int reverse_place=str.length()-1;
  for (int i=1; i<vec_str.size(); i++) {
    if (vec_str[i]!=vec_str[i-1]) {
      perm_counter_sub*=(factorial(factorial_value)/factorial(reverse_place))/(factorial(factorial_value-reverse_place));
      factorial_value=reverse_place;
    }
    reverse_place--;
  }

  str_counted[vec_str]=true;
  return perm_counter_sub;

}

int main () {

  int N,K;
  scanf("%d%d",&N,&K);
  string str;
  cin>>str;

  ll answer=0;

  if (K==0) {

    answer=perm_counter(str);

  }

  else {

    if (K==1) {

      int star_loc=str.find("*");
      for (int i=0; i<26; i++) {
        string str_copy=str;
        str_copy[star_loc]=alph[i];
        answer+=perm_counter(str_copy);
      }

    }

    else {

      int star_loc_1=str.find("*"),star_loc_2;
      for (int i=star_loc_1+1; i<str.length(); i++) {
        if (str[i]=='*') {
          star_loc_2=i;
          break;
        }
      }

      for (int i=0; i<26; i++) {
        for (int j=0; j<26; j++) {
          string str_copy=str;
          str_copy[star_loc_1]=alph[i];
          str_copy[star_loc_2]=alph[j];
          answer+=perm_counter(str_copy);
        }
      }

    }

  }

  printf("%lld\n",answer);

  return 0;

}