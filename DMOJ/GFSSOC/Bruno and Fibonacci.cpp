#include <bits/stdc++.h>
using namespace std;

const int M1 = 5e2 + 5;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  string S;
  cin >> S;

  int last = 0, fib_value = 1;
  set<int> fib_values;
  while(fib_value <= M1) {
    fib_values.insert(fib_value);
    int last_fib_value = fib_value;
    fib_value += last;
    last = last_fib_value;
  } 

  for(int i = 0; i < N; i++) {
    int index = i + 1;
    if(fib_values.count(index) && S[i] != 'A') {
      cout << "Bruno, GO TO SLEEP\n";
      return 0;
    }
    if(!fib_values.count(index) && S[i] == 'A') {
      cout << "Bruno, GO TO SLEEP\n";
      return 0;
    }
  }
  cout << "That's quite the observation!\n";

  return 0;
}