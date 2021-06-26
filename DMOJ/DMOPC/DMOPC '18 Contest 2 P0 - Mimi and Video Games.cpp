#include <cstdio>
#include <algorithm>
using namespace std;

int N, a, R;

int main() {

  scanf("%d%d%d", &N, &a, &R);

  printf("%d", min(N, R / a));

  return 0;
}