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
 
int t;
int n; Ve<In> p;
Ve<In> positions;
bool valid;
 
RI main() { fast_inputandoutput
 
  cin >> t;
 
  while(t--) {
    cin >> n;
    p.Cl(); p.RS(n);
    positions.Cl(); positions.RS(n + 1);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
      positions[p[i]] = i;
    }
 
    valid = true;
    int counted = 0, curr_number = 1, last_index = n - 1;
    while(counted < n) {
      int next_last = positions[curr_number] - 1;
      for(int i = positions[curr_number]; i <= last_index; i++) {
        if(i != positions[curr_number] && p[i] != curr_number) {
          valid = false;
          break;
        }
        curr_number++;
        counted++;
      }
      if(!valid) break;
      last_index = next_last;
    }
 
    if(valid) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
 
  return 0;
}