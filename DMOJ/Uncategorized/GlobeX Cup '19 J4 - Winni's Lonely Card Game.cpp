#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main () {

long long int n;
long long int m;
long long int k;

cin>>n;
cin>>m;
cin>>k;

long long int number;

long long int occured[100000];

map <long long int,long long int> frequency;

long long int occured_counter=0;

for (int i=1; i<=n; i++) {

cin>>number;

if (frequency.count(number)==0) {
  frequency[number]=1;
  occured[occured_counter]=number;
  occured_counter++;
}

else
  frequency[number]++;

}

long long int amounts[100000];

for (int i=0; i<=occured_counter-1; i++)
amounts[i]=frequency[occured[i]];

sort(amounts,amounts+occured_counter);

long long int moves_left=k;

long long int i=occured_counter-1;

unsigned long long int score=0;

while (moves_left>0) {

if (moves_left<amounts[i]) {
  score+=(moves_left-1)*(moves_left)/2;
  moves_left=0;
}

else {

  score+=(amounts[i]-1)*(amounts[i])/2;
  moves_left-=amounts[i];
  i--;

}

}

cout<<score<<endl;

return 0;

}