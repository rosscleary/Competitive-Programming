#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
 
#define fast_inputandoutput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
 
#define In int
#define RI int32_t
#define ULL unsigned long long
#define Do double
#define Bo bool
#define Ch char
#define St string
#define Pa pair
 
#define Ve vector
#define Li list
#define Sta stack
#define Qe queue
#define PQ priority_queue
#define Se set
#define Ma map
 
#define Le length
#define Su substr
#define Fin find
#define Ins insert
#define Er erase
#define STI stoi
#define TS to_string
#define Fi first
#define Sec second
#define MP make_pair
#define So sort
#define MS memset
#define SO sizeof
#define Cl clear
#define RS resize
#define Si size
#define Be begin
#define En end
#define PB push_back
#define PF push_front
#define Em empty
#define Fr front
#define PFr pop_front
#define Pu push
#define Po pop
 
const int Inf = 1e18, Ninf = -1e18, Mod = 1e9 + 7;
const double Eps = 1e-6;
const string Alph_lower("abcdefghijklmnopqrstuvwxyz"), Alph_upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), Digits("0123456789");
 
void Max_self(int &original_value, int new_value) { 
  original_value = max(original_value, new_value); 
}
void Min_self(int &original_value, int new_value) { 
  original_value = min(original_value, new_value); 
}
void To_lowercase(string &str) { 
  for(int i = 0; i < str.length(); i++) str[i] = tolower((str[i])); 
}
void To_uppercase(string &str) { 
  for(int i = 0; i < str.length(); i++) str[i] = toupper(str[i]); 
}
bool Is_prime(int num) { 
  if(num == 1) return false;
  if(num == 2) return true; 
  for(int div = 2; div <= sqrt(num); div++) {
    if(num % div == 0) return false; 
  }  
  return true; 
}
int GCD(int num_1, int num_2) { 
  return num_2 != 0 ? GCD(num_2, num_1 % num_2) : num_1; 
}
 
// ---------- END OF TEMPLATE ---------- //
 
const string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
const int digit_amounts[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
 
const int M1 = 2e3 + 5;
 
bool valid_next(string start, string end) {
  for(int i = 0; i < 7; i++) {
    if(start[i] == '1' && end[i] == '0') return false;
  }
  return true;
}
 
int n, k;
string start[M1];
int start_amount[M1];
 
bool dp[M1][M1];
 
RI main() { fast_inputandoutput
 
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> start[i];
    for(int j = 0; j < 7; j++) start_amount[i] += start[i][j] - '0';
  }
 
  // for(int i = 0; i < 10; i++) {
  //   if(start_amount[n - 1] <= digit_amounts[i]) dp[n - 1][digit_amounts[i] - start_amount[n - 1]] = true;
  // }
 
  dp[n][0] = true;
  for(int i = n - 1; i > 0; i--) {
    for(int left = 0; left <= k; left++) {
      for(int digit = 0; digit < 10; digit++) {
        int increase = digit_amounts[digit] - start_amount[i];
        if(increase >= 0 && valid_next(start[i], digits[digit]) && dp[i + 1][left - increase]) {
          dp[i][left] = true;
          break;
        }
      }
    }
  }
 
  int amount_left = k;
  for(int i = 0; i < n; i++) {
    bool possible = false;
    for(int digit = 9; digit >= 0; digit--) {
      int increase = digit_amounts[digit] - start_amount[i];
      if(increase >= 0 && valid_next(start[i], digits[digit]) && dp[i + 1][amount_left - increase]) {
        cout << digit;
        amount_left -= increase;
        possible = true;
      }
      if(possible) break;
    }
    if(!possible) {
      cout << "-1" << endl;
      return 0;
    }
  }
 
  cout << endl;
 
  return 0;
}