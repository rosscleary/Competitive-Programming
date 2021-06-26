#include <bits/stdc++.h>
using namespace std;
 
const int maxvalue = 100;
 
int t;
int n, x;
bool place_occured[maxvalue + 1]; vector<int> unique_places;
int answer;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n >> x;
 
    unique_places.push_back(0);
    for(int i = 0; i < n; i++) {
      int place; cin >> place;
      if(!place_occured[place]) unique_places.push_back(place);
      place_occured[place] = true;
    }
    sort(unique_places.begin(), unique_places.end());
 
 
    for(int i = 1; i < unique_places.size(); i++) {
      if(unique_places[i] - unique_places[i - 1] - 1 > x) {
        answer = unique_places[i - 1] + x;
        x = 0;
        break;
      } else {
        answer = unique_places[i];
        x -= unique_places[i] - unique_places[i - 1] - 1;
      }
    }
    cout << answer + x << "\n";
 
    memset(place_occured, false, sizeof(place_occured));
    unique_places.clear();
  }
 
  return 0;
}