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

int main () {

  int k;
  cin>>k;

  map <string,char> letter_codes;
  vector <string> codes_occured;

  char letter;
  string letter_code;
  for (int i=1; i<=k; i++) {
    cin>>letter;
    cin>>letter_code;
    letter_codes[letter_code]=letter;
    codes_occured.push_back(letter_code);
  }

  string letter_sequence;
  cin>>letter_sequence;

  int current_start=0;
  while (current_start<letter_sequence.length()) {

    int search_length=1;
    bool keep_going=true;
    while (keep_going) {

      string search=letter_sequence.substr(current_start,search_length);

      for (int i=0; i<codes_occured.size(); i++) {
        if (search==codes_occured[i]) {
          cout<<letter_codes[search];
          current_start+=search_length;
          keep_going=false;
          break;
        }
      }

      search_length++;

    }

  }

  return 0;

}