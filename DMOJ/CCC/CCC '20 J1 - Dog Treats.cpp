#include <bits/stdc++.h>
using namespace std;

int main ()

{

  int S, M, L;
  scanf("%d%d%d", &S, &M, &L);

  (S + 2 * M + 3 * L >= 10) ? printf("happy\n") : printf("sad\n");

  return 0;

}