#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int num_ways(int team, vector<pair<int,int>> to_play, int current, int scores[5]) {

if (current==to_play.size()) {

int largest=0;

int best_i;

for (int i=1; i<=4; i++) {
    
if (scores[i]>largest) {
    largest=scores[i];
    best_i=i;
}

}

int repeat_counter=0;

for (int i=1; i<=4; i++) {

if (scores[i]==largest)
    repeat_counter=repeat_counter+1;

}

if (best_i==team && repeat_counter==1)
    return 1;    

else
    return 0;
  
}

int result_1;
int result_2;
int result_3;

int scores_copy_1[5];

for (int i=0; i<=4; i++)
scores_copy_1[i]=scores[i];

scores_copy_1[to_play[current].first]=scores_copy_1[to_play[current].first]+3;

result_1=num_ways(team,to_play,current+1,scores_copy_1);
    
int scores_copy_2[5];

for (int i=0; i<=4; i++)
scores_copy_2[i]=scores[i];

scores_copy_2[to_play[current].second]=scores_copy_2[to_play[current].second]+3;

result_2=num_ways(team,to_play,current+1,scores_copy_2);
    
int scores_copy_3[5];

for (int i=0; i<=4; i++)
scores_copy_3[i]=scores[i];

scores_copy_3[to_play[current].first]=scores_copy_3[to_play[current].first]+1;
scores_copy_3[to_play[current].second]=scores_copy_3[to_play[current].second]+1;

result_3=num_ways(team,to_play,current+1,scores_copy_3);
    
return result_1+result_2+result_3;
    
}

int main () {
    
int team;

cin>>team;

int num_games;

cin>>num_games;

bool dones[4][5]={false};

int scores[5]={0};
    
int a;
int b;

int a_s;
int b_s;

for (int i=1; i<=num_games; i++) {

cin>>a;
cin>>b;
    
cin>>a_s;
cin>>b_s;

dones[a][b]=true;

if (a_s>b_s)
    scores[a]=scores[a]+3;

else {
    
if (b_s>a_s)
    scores[b]=scores[b]+3;
    
else {
    scores[a]=scores[a]+1;
    scores[b]=scores[b]+1;
}
    
}   
    
}  

vector <pair<int,int>> to_play;

for (int i=1; i<=3; i++) {

    for (int ii=i+1; ii<=4; ii++) {
    
    if (dones[i][ii]==false)
        to_play.push_back(make_pair(i,ii));
        
    }
      
}

int current=0;

cout<<num_ways(team,to_play,current,scores)<<endl;

return 0;

}