#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;
int main () {

int num_ants,num_eyes;
cin>>num_ants>>num_eyes;

bool troy=false;
bool vlad=false;
bool graeme=false;

if (num_ants>=3 && num_eyes<=4) {
  troy=true;
}

if (num_ants<=6 && num_eyes>=2) {
  vlad=true;
}

if (num_ants<=2 && num_eyes<=3) {
  graeme=true;
}

if (troy) {
  cout<<"TroyMartian"<<endl;
}

if (vlad) {
  cout<<"VladSaturnian"<<endl;
}

if (graeme) {
  cout<<"GraemeMercurian"<<endl;
}

return 0;

}