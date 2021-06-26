#include <stdlib.h>

int main ()

{

  int a, b, c, d, t;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &t);

  int shortest_path = abs(a - c) + abs(b - d);

  (shortest_path <= t && (t - shortest_path) % 2 == 0) ? printf("Y\n") : printf("N\n");

  return 0;

}