#include <bits/stdc++.h>
using namespace std;

#define int long long int
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
  return (num_2 != 0) ? GCD(num_2, num_1 % num_2) : num_1; 
}

// ---------- END OF TEMPLATE ---------- //

int N, K;
Ve<In> widths;
int answer;

RI main() { fast_inputandoutput

  cin >> N >> K;
  widths.RS(N);
  for(int i = 0; i < N; i++) cin >> widths[i];

  sort(widths.begin(), widths.end());

  int last_width = widths[N - 1];
  answer = 1;
  for(int i = N - 2; i >= 0; i--) {
    if(last_width - widths[i] >= K) {
      last_width = widths[i];
      answer++;
    }
  }

  cout << answer << endl;

  return 0;
}