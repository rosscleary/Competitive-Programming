#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define double long double
#define endl "\n"
 
#define In int
#define ULL unsigned long long
#define Do double
#define Bo
#define Ch char
#define St string
 
#define Ve vector
#define Ma map
#define Se set
#define Qe queue
#define PQ priority_queue
#define Li list
#define Sta stack
 
#define Fi first
#define Sec second
#define MP make_pair
#define So sort
#define MS memset
#define SO sizeof
#define Le length
#define Su substr
#define Fin find
#define Ins insert
#define Er erase
#define STI stoi
#define TS to_string
#define Cl clear
#define Si size
#define PB push_back
#define Be begin
#define En end
#define PF push_front
#define PFr pop_front
#define Pu push
#define Po pop
#define UB upper_bound
#define LB lower_bound
 
const int Inf = 1e18, Ninf = -1e18, Mod = 1e9 + 7;
const double Eps = 1e-6;
const string Alph_lower("abcdefghijklmnopqrstuvwxyz"), Alph_upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), Digits("0123456789");
 
void Max_self(int &original_value, int new_value) { original_value = max(original_value, new_value); }
void Min_self(int &original_value, int new_value) { original_value = min(original_value, new_value); }
void To_lowercase(string &str) { for(int i = 0; i < str.length(); i++) str[i] = tolower((str[i])); }
void To_uppercase(string &str) { for(int i = 0; i < str.length(); i++) str[i] = toupper(str[i]); }
bool Is_prime(int num) { if(num == 2) return true; for(int div = 2; div <= sqrt(num); div++) if(!(num % div)) return false; return true; }
int GCD(int num_1, int num_2) { return num_2 ? GCD(num_2, num_1 % num_2) : num_1; }
 
// ---------- END OF TEMPLATE ---------- //
 
const int M1 = 2e5 + 5;
 
int t;
int n, a[M1];
int answer;
 
int32_t main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
 
    if(n == 1) {
      cout << a[0] << endl;
      continue;
    }
 
    if(a[n - 1] > 0) a[n] = -1;
    else a[n] = 1;
    answer = 0;
    int last_max = a[0];
    for(int i = 1; i <= n; i++) {
      if(a[i] > 0 != a[i - 1] > 0) {
        answer += last_max;
        last_max = a[i];
      } else Max_self(last_max, a[i]);
    }
 
    cout << answer << endl; 
  }
 
  return 0;
}