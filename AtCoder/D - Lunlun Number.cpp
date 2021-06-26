#include <bits/stdc++.h>
using namespace std;
 
const string digits[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const string digits_string("0123456789");
 
int K;
vector<string> valid_numbers;
 
void generate_number(int length, string current, bool start) {
 
  if(current.length() == length) {
    valid_numbers.push_back(current);
    return;
  }
 
  if(start) {
    for(int i = 1; i < 10; i++) {
      generate_number(length, current + digits[i], false);
    }
    return;
  }
 
  int last_digit = current[current.length() - 1];
 
  if(last_digit == '0') {
    generate_number(length, current + '0', false);
    generate_number(length, current + '1', false);
    return;
  }
  if(last_digit == '9') {
    generate_number(length, current + '8', false);
    generate_number(length, current + '9', false);
    return;
  }
 
  generate_number(length, current + digits[digits_string.find(last_digit) - 1], false);
  generate_number(length, current + digits[digits_string.find(last_digit)], false);
  generate_number(length, current + digits[digits_string.find(last_digit) + 1], false);  
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> K;
 
  for(int length = 1; length <= 10; length++) generate_number(length, "", true);
 
  cout << valid_numbers[K - 1] << "\n";
 
  return 0;
}