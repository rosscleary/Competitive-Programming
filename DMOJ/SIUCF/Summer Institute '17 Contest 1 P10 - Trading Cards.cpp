#include <cstdio>
using namespace std;

int main () {

  int n;
  scanf("%d",&n);
  int a_values[200];
  for (int i=0; i<n; i++) {
    scanf("%d",&a_values[i]);
  }

  int a_value=0;
  for (int i=0,amount; i<n; i++) {
    scanf("%d",&amount);
    a_value+=amount*a_values[i];
  }

  int m;
  scanf("%d",&m);
  int c_values[200];
  for (int i=0; i<m; i++) {
    scanf("%d",&c_values[i]);
  }

  int c_value=0;
  for (int i=0,amount; i<m; i++) {
    scanf("%d",&amount);
    c_value+=amount*c_values[i];
  }

  printf("%d %d",a_value,c_value);

  return 0;

}