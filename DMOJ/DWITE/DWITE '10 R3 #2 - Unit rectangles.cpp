#include <bits/stdc++.h>
using namespace std;

int test_case = 5, N;

int query_answers[1005] = {0};

int main() 

{

  for (int N_value = 1; N_value <= 1000; N_value++)
  {
    int answer = 0;
    for (int factor = 1; factor <= sqrt(N_value); factor++)
    {
      if (N_value % factor == 0)
        answer++;
    }
    query_answers[N_value] = query_answers[N_value - 1] + answer;
  }

  while (test_case--)
  {
    scanf("%d", &N);
    printf("%d\n", query_answers[N]);
  }

  return 0;

}