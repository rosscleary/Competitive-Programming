#include <bits/stdc++.h>
using namespace std;

class Roman {
  public:
  Roman(int);
  Roman(string);
  void add(Roman);
  string get_roman_value();

  private:
  int num_value = 0;
  string roman_value = "";
  void set_roman_value();
  void set_num_value();
};

void Roman::set_roman_value() {
  if(num_value > 1000) {
    roman_value = "CONCORDIA CUM VERITATE";
    return;
  }
  vector<pair<string, int>> symbols = {
    {"M", 1000}, 
    {"CM", 900}, 
    {"D", 500}, 
    {"CD", 400}, 
    {"C", 100}, 
    {"XC", 90}, 
    {"L", 50}, 
    {"XL", 40}, 
    {"X", 10}, 
    {"IX", 9}, 
    {"V", 5}, 
    {"IV", 4}, 
    {"I", 1}
  };

  roman_value = "";
  int value_remain = num_value;
  while(value_remain > 0) {
    for(auto i : symbols) {
      if(i.second <= value_remain) {
        roman_value += i.first;
        value_remain -= i.second;
        break;
      }
    }
  }
}

void Roman::set_num_value() {
  map<char, int> char_values = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  for(auto i : roman_value) {
    num_value += char_values[i];
  }

  for(int i = 0; i < roman_value.size() - 1; i++) {
    if(roman_value[i] == 'I' && (roman_value[i + 1] == 'V' || roman_value[i + 1] == 'X')) {
      num_value -= 2;
    } else if(roman_value[i] == 'X' && (roman_value[i + 1] == 'L' || roman_value[i + 1] == 'C')) {
      num_value -= 20;
    } else if(roman_value[i] == 'C' && (roman_value[i + 1] == 'D' || roman_value[i + 1] == 'M')) {
      num_value -= 200;
    }
  }
}

Roman::Roman(int num_value) {
  this->num_value = num_value;
  set_roman_value();
}

Roman::Roman(string roman_value) {
  this->roman_value = roman_value;
  set_num_value();
}

void Roman::add(Roman other) {
  num_value += other.num_value;
  set_roman_value();
}

string Roman::get_roman_value() {
  return roman_value;
}

void solve_tc() {
  string operation;
  cin >> operation;

  Roman roman(operation.substr(0, operation.find('+')));
  Roman added_roman(operation.substr(operation.find('+') + 1, operation.size() - operation.find('+')));

  roman.add(added_roman);
  cout << operation << roman.get_roman_value() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int tc;
  cin >> tc;
  while(tc--) {
    solve_tc();
  }

  return 0;
}