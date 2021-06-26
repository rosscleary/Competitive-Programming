#include <bits/stdc++.h>
using namespace std;

map<char, string> suit_names {
  {'C', "Clubs"},
  {'D', "Diamonds"},
  {'H', "Hearts"},
  {'S', "Spades"}
};

map<char, int> card_values {
  {'A', 4},
  {'K', 3},
  {'Q', 2},
  {'J', 1}
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string cards;
  cin >> cards;

  int points, card_cnt, total = 0;
  cout << "Cards Dealt Points\n";
  for(auto i: cards) {
    if(suit_names.count(i)) {
      if(i != 'C') {
        cout << points + max(0, 3 - card_cnt) << '\n';
        total += points + max(0, 3 - card_cnt);
      }
      points = 0, card_cnt = 0;
      cout << suit_names[i] << ' ';
      continue;
    }
    points += card_values[i], card_cnt++; 
    cout << i << ' ';
  }
  cout << points + max(0, 3 - card_cnt) << '\n';
  total += points + max(0, 3 - card_cnt);
  cout << "Total " << total << '\n';

  return 0;
}