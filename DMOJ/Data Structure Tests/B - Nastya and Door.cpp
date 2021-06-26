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
int n, k; Ve<In> a;
int answer;
 
RI main() { fast_inputandoutput
 
  cin >> t;
  
  while(t--) {
    cin >> n >> k;
    a.Cl();
    a.RS(n);
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int num_peaks_start = 0;
    for(int i = 0; i < k; i++) {
      if(i != 0 && i != k - 1 && a[i] > a[i - 1] && a[i] > a[i + 1]) num_peaks_start++;
    }
 
    int left = 1, right = k;
    int num_peaks = num_peaks_start;
    answer = num_peaks_start;
    while(right < n) {
      if(a[left] > a[left - 1] && a[left] > a[left + 1]) num_peaks--;
      if(a[right - 1] > a[right - 2] && a[right - 1] > a[right]) num_peaks++;
      left++;
      right++;
      Max_self(answer, num_peaks);
    }
 
    if(num_peaks_start == answer) {
      cout << answer + 1 << " 1" << endl;
      continue;
    }
 
    left = 1, right = k;
    num_peaks = num_peaks_start;
    while(right < n) {
      if(a[left] > a[left - 1] && a[left] > a[left + 1]) num_peaks--;
      if(a[right - 1] > a[right - 2] && a[right - 1] > a[right]) num_peaks++;
      if(num_peaks == answer) {
        cout << answer + 1 << " " << left + 1 << endl;
        break;
      }
      left++;
      right++;
    }
  }
 
  return 0;
}