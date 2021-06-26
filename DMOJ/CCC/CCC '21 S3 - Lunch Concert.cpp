#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e18;

struct change {
  int point_value, type, amount;
};

bool sort_fun(change value_1, change value_2) {
  return value_1.point_value < value_2.point_value;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> P(N), W(N), D(N);
  map<int, int> right_inc, left_inc;
  for(int i = 0; i < N; i++) {
    cin >> P[i] >> W[i] >> D[i];
    right_inc[P[i] + D[i]] += W[i];
    left_inc[P[i] - D[i]] += W[i];
  }

  vector<change> options;
  for(auto i: right_inc) {
    options.push_back({i.first, 1, i.second});
  }
  for(auto i: left_inc) {
    options.push_back({i.first, 0, i.second});
  }
  sort(options.begin(), options.end(), sort_fun);
  
  vector<int> option_values;
  int right_sum = 0, add_right = 0;
  for(int i = 0; i < options.size(); i++) {
    if(i != 0) {
      option_values.push_back(add_right + right_sum * (options[i].point_value - options[i - 1].point_value));
      add_right = add_right + right_sum * (options[i].point_value - options[i - 1].point_value);
    } else {
      option_values.push_back(0);
    }
    if(options[i].type == 1) {
      right_sum += options[i].amount;
    }
  }
  int left_sum = 0, add_left = 0;
  for(int i = options.size() - 1; i >= 0; i--) {
    if(i != options.size() - 1) {
      option_values[i] += add_left + left_sum * (options[i + 1].point_value - options[i].point_value);
      add_left = add_left + left_sum * (options[i + 1].point_value - options[i].point_value);
    }
    if(options[i].type == 0) {
      left_sum += options[i].amount;
    }
  }

  int ans = M1;
  for(auto i: option_values) {
    ans = min(ans, i);
  }

  cout << ans << '\n';

  return 0;
}