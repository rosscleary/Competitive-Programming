#include <bits/stdc++.h>
using namespace std;

int hour, minute;
int real_time; double travel_time = 0.0;
int end_hour, end_minute;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  char colon; cin >> hour >> colon >> minute;

  real_time = (hour * 60) + minute;
  while(travel_time < 120.0) {
    if((real_time >= 420 && real_time < 600) || (real_time >= 900 && real_time < 1140)) travel_time += 0.5;
    else travel_time++;
    real_time++;
  }

  real_time %= 1440;
  end_hour = real_time / 60;
  end_minute = real_time % 60;

  if(end_hour < 10) cout << "0";
  cout << end_hour << ":";
  if(end_minute < 10) cout << "0";
  cout << end_minute;
  cout << "\n";

  return 0;
}