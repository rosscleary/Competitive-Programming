#include <bits/stdc++.h>
using namespace std;
 
string invalid = "34679";
 
unordered_map<char, char> reverse_digit = {
  {'0', '0'},
  {'1', '1'},
  {'2', '5'},
  {'5', '2'},
  {'8', '8'},
};
 
void add_lead_zeroes(string &str) {
  while(str.size() < 2) {
    str = '0' + str;
  }
}
 
string reverse_str(string str) {
  string ans = "";
  for(int i = 1; i >= 0; i--) {
    if(invalid.find(str[i]) != -1) {
      return "100";
    }
    ans += reverse_digit[str[i]];
  }
 
  return ans;
}
 
void solve_tc() {
  int h, m;
  string s;
  cin >> h >> m >> s;
 
  for(int hour = stoi(s.substr(0, 2)); hour < h; hour++) {
    for(int min = hour == stoi(s.substr(0, 2)) ? stoi(s.substr(3, 2)) : 0; min < m; min++) {
      string hour_str = to_string(hour), min_str = to_string(min);
      add_lead_zeroes(hour_str), add_lead_zeroes(min_str);
      if(stoi(reverse_str(hour_str)) < m && stoi(reverse_str(min_str)) < h) {
        cout << hour_str << ':' << min_str << '\n';
        return;
      }
    }
  }
 
  cout << "00:00\n";
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int T;
  cin >> T;
  while(T--) {
    solve_tc();
  }
 
  return 0;
}