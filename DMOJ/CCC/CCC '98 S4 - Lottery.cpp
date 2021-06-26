#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

string original_string;

void print_string(string);
bool is_operator(string);
int last_operator(string);

int main () {

  int n;
  cin>>n;
  cin.ignore();

  for (int test_case=1; test_case<=n; test_case++) {

    getline(cin,original_string);

    print_string(original_string);
    cout<<endl<<endl;

  }

  return 0;

}

void print_string(string str) {

  if (!is_operator(str)) {
    cout<<str;
    return;
  }

  int last=last_operator(str);

  if (str==original_string) {

    string new_str_1=str.substr(0,last-1);
    string new_str_2=str.substr(last+2,(str.length()-1)-(last+2)+1);

    print_string(new_str_1);
    cout<<" "<<str[last]<<" ";
    print_string(new_str_2);

  }

  else {

    string new_str_1=str.substr(0,last-1);
    string new_str_2=str.substr(last+2,(str.length()-1)-(last+2)+1);

    cout<<"(";
    print_string(new_str_1);
    cout<<" "<<str[last]<<" ";
    print_string(new_str_2);
    cout<<")";
    
  }

}

bool is_operator(string str) {

  int find_times=str.find('X');
  int find_minus=str.find('-');
  int find_plus=str.find('+');

  if (find_times>=0 && find_times<80) {
    return true;
  }

  if (find_plus>=0 && find_plus<80) {
    return true;
  }

  if (find_minus>=0 && find_minus<80) {
    return true;
  }

  return false;

}

int last_operator(string str) {

  int last;
  bool last_times=true;
  for (int i=0; i<str.length(); i++) {

    if (str[i]=='X') {
      if (last_times) {
        last=i;
      }
    }

    else {
      if (str[i]=='+' || str[i]=='-') {
        last_times=false;
        last=i;
      }
    }

  }

  return last;

}