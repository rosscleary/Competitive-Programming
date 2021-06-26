#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
#include <climits>
#define ll long long
using namespace std;

int main () {

  int n;
  cin>>n;
  while (n--) {

    int s,v,o;
    cin>>s>>v>>o;
    vector<string> subjects;
    vector<string> verbs;
    vector<string> objects;
    cin.ignore();
    string subject;
    for (int i=0; i<s; i++) {
      getline(cin,subject);
      subjects.push_back(subject);
    }
    string verb;
    for (int i=0; i<v; i++) {
      getline(cin,verb);
      verbs.push_back(verb);
    }
    string object;
    for (int i=0; i<o; i++) {
      getline(cin,object);
      objects.push_back(object);
    }

    for (int i=0; i<subjects.size(); i++) {
      for (int j=0; j<verbs.size(); j++) {
        for (int k=0; k<objects.size(); k++) {
          cout<<subjects[i]<<" "<<verbs[j]<<" "<<objects[k]<<"."<<endl;
        }
      }
    }

  }


  return 0;

}