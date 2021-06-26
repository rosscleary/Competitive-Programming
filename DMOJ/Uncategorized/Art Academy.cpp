#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
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

void Max_self(int &original_value, int new_value) { original_value = max(original_value, new_value); }
void Min_self(int &original_value, int new_value) { original_value = min(original_value, new_value); }
void To_lowercase(string &str) { for(int i = 0; i < str.length(); i++) str[i] = tolower((str[i])); }
void To_uppercase(string &str) { for(int i = 0; i < str.length(); i++) str[i] = toupper(str[i]); }
bool Is_prime(int num) { if(num == 2) return true; for(int div = 2; div <= sqrt(num); div++) if(!(num % div)) return false; return true; }
int GCD(int num_1, int num_2) { return num_2 ? GCD(num_2, num_1 % num_2) : num_1; }

// ---------- END OF TEMPLATE ---------- //

const int M1 = 2e1 + 5;

int N, h[M1];
int num_lines = 0;

RI main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> h[i];
    Max_self(num_lines, h[i]);
  }

  for(int line = num_lines - 1; line >= 0; line--) {
    for(int segment = 0; segment < N; segment++) {
      int num_chars = max(0, RI(h[segment] - line));
      if(num_chars == 0) {
        for(int i = 0; i < 2 * h[segment]; i++) cout << " ";
      } else {
        for(int i = 0; i < (((2 * h[segment]) - 1) - ((2 * num_chars) - 1)) / 2; i++) cout << " ";
        for(int i = 0; i < num_chars; i++) cout << "^ ";
        for(int i = 0; i < (((2 * h[segment]) - 1) - ((2 * num_chars) - 1)) / 2; i++) cout << " ";
      }
    }
    cout << endl;
  }

  return 0;
}