#include <bits/stdc++.h>
using namespace std;

int test_case = 5;
string number;

int digit_sum(int number) {
  int sum = 0;

  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }

  return sum;
} 

int check_digit(string number) {
  int sum = 0;

  int number_length = number.length();
  for (int i = number_length - 1; i >= 0; i--) {
    if ((number_length - i) % 2 == 1) {
      sum += digit_sum((number[i] - '0') * 2);
    } else {
      sum += number[i] - '0';
    }
  }

  return (10 - (sum % 10)) % 10;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (test_case--) {
    for (int i = 0; i < 5; i++) {
      cin >> number;
      cout << check_digit(number);
    }

    cout << endl;
  }

  return 0;
}