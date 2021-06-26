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

string alphabet("abcdefghijklmnopqrstuvwxyz");

int k;
cin>>k;

string letters;
cin>>letters;

string new_letters=letters;

map <char,int> letter_frequency;

for (int i=0; i<=k-1; i++) {
  if (letter_frequency.count(letters[i])==0) {
    letter_frequency[letters[i]]=1;
  }
  else {
    letter_frequency[letters[i]]++;
  }
}

int most_frequent_amount=0;
int shift;

for (int i=25; i>=0; i--) {
  if (letter_frequency[alphabet[i]]>=most_frequent_amount) {
    most_frequent_amount=letter_frequency[alphabet[i]];
    shift=i+1;
  }
}

new_letters[k]=alphabet[(alphabet.find(letters[k])+shift)%26];

for (int i=k+1; i<=letters.length()-1; i++) {
  if (letter_frequency.count(letters[i-1])==0) {
    letter_frequency[letters[i-1]]=1;
  }
  else {
    letter_frequency[letters[i-1]]++;
  }
  letter_frequency[letters[i-k-1]]--;
  int most_frequent_amount=0;
  int shift;
  for (int ii=25; ii>=0; ii--) {
    if (letter_frequency[alphabet[ii]]>=most_frequent_amount) {
      most_frequent_amount=letter_frequency[alphabet[ii]];
      shift=ii+1;
    }
  }
  new_letters[i]=alphabet[(alphabet.find(letters[i])+shift)%26];
}

cout<<new_letters<<endl;

return 0;

}