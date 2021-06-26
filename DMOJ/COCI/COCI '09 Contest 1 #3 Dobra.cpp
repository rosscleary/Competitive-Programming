#include <bits/stdc++.h>
using namespace std;

#define int long long

const string vow = "AEIOU", cons = "BCDFGHJKLMNPQRSTVWXYZ";
const int M1 = 5, M2 = 21;

int L_cnt_start = 0;
string real_str = "";
int ans = 0;

bool valid(string choice) {
  return choice.find("vvv") == -1 && choice.find("ccc") == -1;
}

void generate(int i, string curr, int L_cnt, int vow_cnt, int cons_cnt) {
  if(i == real_str.size()) {
    if(L_cnt_start + L_cnt > 0 && valid(curr)) {
      ans += powl(5, vow_cnt) * powl(20, cons_cnt);
    } 
    return;
  }

  if(real_str[i] == '_') {
    generate(i + 1, curr + 'c', L_cnt + 1, vow_cnt, cons_cnt);
    generate(i + 1, curr + 'v', L_cnt, vow_cnt + 1, cons_cnt);
    generate(i + 1, curr + 'c', L_cnt, vow_cnt, cons_cnt + 1);
  } else {
    generate(i + 1, curr + real_str[i], L_cnt, vow_cnt, cons_cnt);
  }
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string str;
  cin >> str;
  for(auto i: str) {
    L_cnt_start += i == 'L';
    if(vow.find(i) != -1) {
      real_str += 'v';
    } else if(cons.find(i) != -1) {
      real_str += 'c';
    } else {
      real_str += '_';
    }
  }

  generate(0, "", 0, 0, 0);
  cout << ans << '\n';

  return 0;
}