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

int n;
cin>>n;

for (int t_case=1; t_case<=n; t_case++) {

  string num_1;
  string num_2;

  cin>>num_1;
  cin>>num_2;

  string temp_1=num_1;
  string temp_2=num_2;

  bool minus_in_1=false;
  bool minus_in_2=false;

  if (num_1[0]=='-') {
    temp_1.erase(0,1);
    minus_in_1=true;
  }

  if (num_2[0]=='-') {
    temp_2.erase(0,1);
    minus_in_2=true;
  }

  int minus_counter=0;

  if (minus_in_1) {
    minus_counter++;
  }

  if (minus_in_2) {
    minus_counter++;
  }

  if (temp_1==temp_2 && minus_counter==1) {
    cout<<"0";
  }

  else {

    bool add=true;

    if ((num_1[0]=='-' || num_2[0]=='-') && !(num_1[0]=='-' && num_2[0]=='-')) {
      add=false;
    }

    if (add) {

      bool minus=false;

      if (num_1[0]=='-') {
        num_1.erase(0,1);
        minus=true;
      }

      if (num_2[0]=='-') {
        num_2.erase(0,1);
        minus=true;
      }

      int num_1_counter=num_1.length()-1;
      int num_2_counter=num_2.length()-1;

      vector<int> answer;

      int carry=0;

      while (num_1_counter>=0 || num_2_counter>=0) {
        if (num_1_counter>=0 && num_2_counter>=0) {
          answer.push_back(((num_1[num_1_counter]-'0')+(num_2[num_2_counter]-'0')+carry)%10);
          if ((num_1[num_1_counter]-'0')+(num_2[num_2_counter]-'0')+carry>=10) {
            carry=1;
          }
          else {
            carry=0;
          }
        }
        else {
          if (num_1_counter>=0) {
            answer.push_back(((num_1[num_1_counter]+carry)-'0')%10);
            if ((num_1[num_1_counter]-'0')+carry>=10) {
              carry=1;
            }
            else {
              carry=0;
            }
          }
          else {
            answer.push_back(((num_2[num_2_counter]+carry)-'0')%10);
            if ((num_2[num_2_counter]-'0')+carry>=10) {
              carry=1;
            }
            else {
              carry=0;
            }
          }
        }
        num_1_counter--;
        num_2_counter--;
      }

      if (carry==1) {
        answer.push_back(1);
      }

      if (minus) {
        cout<<"-";
      }

      for (int i=answer.size()-1; i>=0; i--) {
        cout<<answer[i];
      }

    }

    else {

      bool minus_in_1=false;

      if (num_1[0]=='-') {
        minus_in_1=true;
      }

      if (minus_in_1) {
        num_1.erase(0,1);
      }
      else {
        num_2.erase(0,1);
      }

      bool num_1_big_2;

      int num_1_length=num_1.length();
      int num_2_length=num_2.length();

      if (num_1_length>num_2_length) {
        num_1_big_2=true;
      }
      else {
        if (num_2_length>num_1_length) {
          num_1_big_2=false;
        }
        else {
          for (int i=0; i<=num_1_length-1; i++) {
            if ((num_1[i]-'0')>(num_2[i]-'0')) {
              num_1_big_2=true;
              break;
            }
            else {
              if ((num_1[i]-'0')<(num_2[i]-'0')) {
                num_1_big_2=false;
                break;
              }
            }
          }
        }
      }

      if (!num_1_big_2) {
        string temp=num_1;
        num_1=num_2;
        num_2=temp;
      }

      int num_1_counter=num_1.length()-1;
      int num_2_counter=num_2.length()-1;

      vector<int> answer;

      int subtract=0;

      while (num_1_counter>=0 || num_2_counter>=0) {
        if (num_1_counter>=0 && num_2_counter>=0) {
          if ((num_1[num_1_counter]-'0')-subtract>=(num_2[num_2_counter]-'0')) {
            answer.push_back(((num_1[num_1_counter]-'0')-subtract)-(num_2[num_2_counter]-'0'));
            subtract=0;
          }
          else {
            answer.push_back(((num_1[num_1_counter]-'0')-subtract+10)-(num_2[num_2_counter]-'0'));
            subtract=1;
          }
        }
        else {
          if (subtract==1) {
            answer.push_back((num_1[num_1_counter]-'0')-1);
            subtract=0;
          }
          else {
            answer.push_back(num_1[num_1_counter]-'0');
            subtract=0;
          }
        }
        num_1_counter--;
        num_2_counter--;
      }

      if (minus_in_1 && num_1_big_2) {
        cout<<"-";
      }
      else {
        if (!minus_in_1 && !num_1_big_2) {
          cout<<"-";
        }
      }
      bool lead_0=true;
      for (int i=answer.size()-1; i>=0; i--) {
        if (!lead_0 || (lead_0 && answer[i]!=0)) {
          cout<<answer[i];
          lead_0=false;
        }
      }
    }

  }

  cout<<endl;

}

return 0;

}