#include <bits/stdc++.h>
using namespace std;

int main ()

{

  int P, N, R;
  scanf("%d%d%d", &P, &N, &R);

  int people_infected = N, last_infect = N, day;

  for (day = 1; true; day++)
  {
    people_infected += last_infect * R;
    if (people_infected > P) break;
    last_infect *= R;
  }

  printf("%d\n", day);

  return 0;

}