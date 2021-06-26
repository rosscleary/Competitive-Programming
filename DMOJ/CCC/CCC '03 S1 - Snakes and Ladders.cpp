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

  int curr_square=1;
  while (1) {

    int move;
    cin>>move;
    if (curr_square+move<=100) {
      curr_square+=move;
    }
    if (!move) {
      cout<<"You Quit!"<<endl;
      return 0;
    }
    if (curr_square==100) {
      cout<<"You are now on square 100"<<endl<<"You Win!"<<endl;
      return 0;
    }
    if (curr_square==9) {
      curr_square=34;
    }
    else {
      if (curr_square==40) {
        curr_square=64;
      }
      else {
        if (curr_square==67) {
          curr_square=86;
        }
        else {
          if (curr_square==54) {
            curr_square=19;
          }
          else {
            if (curr_square==99) {
              curr_square=77;
            }
            else {
              if (curr_square==90) {
                curr_square=48;
              }
            }
          }
        }
      }
    }
    cout<<"You are now on square "<<curr_square<<endl;
  }

  return 0;

}