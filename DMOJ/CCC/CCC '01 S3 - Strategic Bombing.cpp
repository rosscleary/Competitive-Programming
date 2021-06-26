#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

map <char,vector<char> > graph;

vector <pair <char,char> > used_path;

map <pair<char,char>,int> frequency;

int num_paths;

bool ispath(char point, vector<char> been, vector< pair<char,char> > path) {

if (point=='B') {

  for (int i=0; i<=path.size()-1; i++) {

  if (frequency.count(make_pair(path[i].first,path[i].second))!=0)
    frequency[make_pair(path[i].first,path[i].second)]++;

  else {
    frequency[make_pair(path[i].first,path[i].second)]=1;
    used_path.push_back(make_pair(path[i].first,path[i].second));
  }
  
  }

  num_paths++;

  return true;

}

bool ispath_sub=false;

for (int i=0; i<=graph[point].size()-1; i++) {

bool been_there=false;

for (int ii=0; ii<=been.size()-1; ii++) {

if (been[ii]==graph[point][i]) {
  been_there=true;
  break;
}

}

if (!been_there) {

vector<char> been_copy=been; 
vector< pair<char,char> > path_copy=path;

been_copy.push_back(graph[point][i]);
path_copy.push_back(make_pair(point,graph[point][i]));

if (ispath(graph[point][i],been_copy,path_copy))
  ispath_sub=true;

}

}

return ispath_sub;

}

int main () {

string connect;

while (connect!="**") {

cin>>connect;

if (connect=="**")
  break;

graph[connect[0]].push_back(connect[1]);
graph[connect[1]].push_back(connect[0]);

}

vector<char> been;
vector< pair<char,char> > path;

been.push_back('a');

ispath('A',been,path);

int block_counter=0;

for (int i=0; i<=used_path.size()-1; i++) {

if (frequency[make_pair(used_path[i].first,used_path[i].second)]==num_paths) {
  cout<<used_path[i].first<<used_path[i].second<<endl;
  block_counter++;
}

}

if (block_counter==0)
  cout<<"There are 0 disconnecting roads."<<endl;
else
  cout<<"There are "<<block_counter<<" disconnecting roads."<<endl;

return 0;

}