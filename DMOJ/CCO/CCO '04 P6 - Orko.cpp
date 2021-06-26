#include <bits/stdc++.h>
using namespace std;

const int M1 = 10, M2 = 5, M3 = 1024;
const string colours = "RYGB";

vector<pair<char, int>> A_cards, B_cards;

int dp[M3][M3][2];

int solve(int A_mask, int B_mask, bool A_lead, int rounds_left) {
  if(rounds_left == 0) {
    return 0;
  }
  if(dp[A_mask][B_mask][A_lead] != -1) {
    return dp[A_mask][B_mask][A_lead];
  }

  int ans = -1;
  if(A_lead) {
    for(int i = 0; i < M1; i++) {
      if(!(A_mask & (1 << i))) {
        continue;
      }
      int new_A_mask = A_mask;
      new_A_mask &= ~(1 << i);

      bool colour_found = false;
      for(int j = 0; j < M1; j++) {
        if(B_mask & (1 << j)) {
          if(A_cards[i].first == B_cards[j].first) {
            colour_found = true;
            break;
          }
        }
      }
      
      int other_best = -1;
      for(int j = 0; j < M1; j++) {
        if((B_mask & (1 << j)) && (!colour_found || B_cards[j].first == A_cards[i].first)) {
          int new_B_mask = B_mask;
          new_B_mask &= ~(1 << j);
          if(!colour_found || A_cards[i].second > B_cards[j].second) {
            other_best = max(other_best, rounds_left - 1 - solve(new_A_mask, new_B_mask, true, rounds_left - 1));
          } else {
            other_best = max(other_best, 1 + solve(new_A_mask, new_B_mask, false, rounds_left - 1));
          }
        }
      }

      ans = max(ans, rounds_left - other_best);
    }
  } else {
    for(int i = 0; i < M1; i++) {
      if(!(B_mask & (1 << i))) {
        continue;
      }
      int new_B_mask = B_mask;
      new_B_mask &= ~(1 << i);

      bool colour_found = false;
      for(int j = 0; j < M1; j++) {
        if(A_mask & (1 << j)) {
          if(B_cards[i].first == A_cards[j].first) {
            colour_found = true;
            break;
          }
        }
      }

      int other_best = -1;
      for(int j = 0; j < M1; j++) {
        if((A_mask & (1 << j)) && (!colour_found || A_cards[j].first == B_cards[i].first)) {
          int new_A_mask = A_mask;
          new_A_mask &= ~(1 << j);
          if(!colour_found || B_cards[i].second > A_cards[j].second) {
            other_best = max(other_best, rounds_left - 1 - solve(new_A_mask, new_B_mask, false, rounds_left - 1));
          } else {
            other_best = max(other_best, 1 + solve(new_A_mask, new_B_mask, true, rounds_left - 1));
          }
        }
      }

      ans = max(ans, rounds_left - other_best);
    }
  }

  return dp[A_mask][B_mask][A_lead] = ans;
} 

void solve_tc() {
  A_cards.clear(), B_cards.clear();
  set<pair<char, int>> A_cards_set;
  for(int i = 0; i < M1; i++) {
    string card;
    cin >> card;
    if(card == "*") {
      exit(0);
    }
    A_cards.push_back({card[0], card[1] - '0'}), A_cards_set.insert({card[0], card[1] - '0'});
  }
  for(auto i: colours) {
    for(int j = 1; j <= M2; j++) {
      if(!A_cards_set.count({i, j})) {
        B_cards.push_back({i, j});
      }
    }
  }

  memset(dp, -1, sizeof(dp));
  cout << solve(pow(2, M1) - 1, pow(2, M1) - 1, true, M1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  while(true) {
    solve_tc();
  }

  return 0;
}