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
int GCD(int num_1, int num_2) { return (num_2) ? GCD(num_2, num_1 % num_2) : num_1; }

// ---------- END OF TEMPLATE ---------- //

int values[3];

int32_t main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  for(int i = 0; i < 3; i++) cin >> values[i];
  So(values, values + 3);

  int diff_1 = values[1] - values[0], diff_2 = values[2] - values[1];
  if(diff_1 == diff_2) cout << values[2] + diff_2 << endl;
  else if(diff_1 > diff_2) cout << (values[0] + values[1]) / 2 << endl;
  else cout << (values[1] + values[2]) / 2 << endl;

  return 0;
}