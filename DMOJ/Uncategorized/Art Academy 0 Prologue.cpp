#include <bits/stdc++.h>
using namespace std;

const string digits("0123456789");

int N;
string S;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N;

  while(N--) {
    cin >> S;
    for(int i = 0; i < S.length(); i++) {
      if(S[i] == 'A' || S[i] == 'a') cout << "Hi! ";
      if(S[i] == 'E' || S[i] == 'e') cout << "Bye! ";
      if(S[i] == 'I' || S[i] == 'i') cout << "How are you? ";
      if(S[i] == 'O' || S[i] == 'o') cout << "Follow me! ";
      if(S[i] == 'U' || S[i] == 'u') cout << "Help! ";
      if(digits.find(S[i]) != -1) cout << "Yes! ";
    }
    cout << "\n";
  }

  return 0;
}