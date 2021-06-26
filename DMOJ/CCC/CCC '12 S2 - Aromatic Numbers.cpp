#include <bits/stdc++.h>
using namespace std;

class AromaticNumber {
  public:
  friend class ARAR;
  AromaticNumber(string);
  int decimal_value();

  private:
  string aromatic_number;
  int roman_value(char);
};

int AromaticNumber::roman_value(char roman_char) {
  if (roman_char == 'I') {
    return 1;
  }
  if (roman_char == 'V') {
    return 5;
  }
  if (roman_char == 'X') {
    return 10;
  }
  if (roman_char == 'L') {
    return 50;
  }
  if (roman_char == 'C') {
    return 100;
  }
  if (roman_char == 'D') {
    return 500;
  }
  return 1000;
}

AromaticNumber:: AromaticNumber(string aromatic_number) {
  this->aromatic_number = aromatic_number;
}

int AromaticNumber:: decimal_value() {
  vector<int> values;
  vector<int> roman_values;
  for(int i = 0; i < aromatic_number.size() - 1; i += 2) {
    values.push_back((aromatic_number[i] - '0') * roman_value(aromatic_number[i + 1]));
    roman_values.push_back(roman_value(aromatic_number[i + 1]));
  } 

  int ans = 0;
  for(int i = 0; i < values.size(); i++) {
    if(i == values.size() - 1 || roman_values[i] >= roman_values[i + 1]) {
      ans += values[i];
    } else {
      ans -= values[i];
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string aromatic_number_str;
  cin >> aromatic_number_str;

  AromaticNumber aromatic_number(aromatic_number_str);
  cout << aromatic_number.decimal_value() << '\n';

  return 0;
}

class ARAR {
  public:
  ARAR(AromaticNumber, AromaticNumber);
  int add();
  int subtract();
  int multiply();
  double divide();
  int modulus_divide();

  private:
  AromaticNumber aromatic_number_1 = {0};
  AromaticNumber aromatic_number_2 = {0};
};

ARAR::ARAR(AromaticNumber aromatic_number_1, AromaticNumber aromatic_number_2) {
  this->aromatic_number_1 = aromatic_number_1;
  this->aromatic_number_2 = aromatic_number_2;
}

int ARAR::add() {
  return aromatic_number_1.decimal_value() + aromatic_number_2.decimal_value();
}

int ARAR::subtract() {
  return aromatic_number_1.decimal_value() - aromatic_number_2.decimal_value();
}

int ARAR::multiply() {
  return aromatic_number_1.decimal_value() * aromatic_number_2.decimal_value();
}

double ARAR::divide() {
  return double(aromatic_number_1.decimal_value()) / double(aromatic_number_2.decimal_value());
}

int ARAR::modulus_divide() {
  return aromatic_number_1.decimal_value() % aromatic_number_2.decimal_value();
}