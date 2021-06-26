#include <bits/stdc++.h>
using namespace std;

#define maxa 1000000
#define maxb 1000000

int a, b;
vector<int> factor_occured;
long long factor_freq[maxb + 1] = {0};
long long factor_freq_b[maxb + 1] = {0};

bool is_prime(int num) {
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }
  for (int i = 3; i <= sqrt(num); i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void prime_factors(int num) {
  if (is_prime(num)) {
    if (factor_freq[num] == 0) {
      factor_occured.push_back(num);
    }
    factor_freq[num]++;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      prime_factors(i);
      prime_factors(num / i);
      break;
    }
  }
}

int num_factors(int num, int factor) {
  int counter = 0;

  while (true) {
    if (num % factor != 0) {
      break;
    }
    counter++;
    num /= factor;
  }

  return counter;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;

  prime_factors(a);

  for (int i = 1; i <= b; i++) {
    for (int j = 0; j < factor_occured.size(); j++) {
      factor_freq_b[factor_occured[j]] += num_factors(i, factor_occured[j]);
    }
  }

  long long answer = 1000000000;
  for (int i = 0; i < factor_occured.size(); i++) {
    answer = min(answer, factor_freq_b[factor_occured[i]] / factor_freq[factor_occured[i]]);
  }

  cout << answer << "\n";

  return 0;
}