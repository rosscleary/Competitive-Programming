#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

string cells[11][10];
int cell_values[11][10]={0};
bool calculated_cell_values[11][10]={false};

int cell_value(int,int,vector <vector <bool> >);
int letter_to_number(char);

int main () {

  for (int i=1; i<=10; i++) {
    for (int j=1; j<=9; j++) {
      cin>>cells[i][j];
    }
  }

  for (int i=1; i<=10; i++) {
    for (int j=1; j<=9; j++) {
      if (!calculated_cell_values[i][j]) {
        vector < vector <bool> > visited_start(11,vector <bool> (10));
        cell_values[i][j]=cell_value(i,j,visited_start);
      }
    }
  }

  for (int i=1; i<=10; i++) {
    for (int j=1; j<=9; j++) {
      if (cell_values[i][j]==-1) {
        cout<<"* ";
      }
      else {
        cout<<cell_values[i][j]<<" ";
      }
    }
    cout<<endl;
  }

  return 0;

}

int cell_value(int row, int col, vector < vector <bool> > visited) {

  if (calculated_cell_values[row][col]) {
    return cell_values[row][col];
  }

  if (cells[row][col].find('+')==-1 && cells[row][col][0]-'0'<=9) {
    int pow_10_counter=0;
    for (int i=cells[row][col].length()-1; i>=0; i--) {
      cell_values[row][col]+=pow(10,pow_10_counter)*(cells[row][col][i]-'0');
      pow_10_counter++;
    }
    calculated_cell_values[row][col]=true;
    return cell_values[row][col];
  }

  if (visited[row][col]) {
    calculated_cell_values[row][col]=true;
    return cell_values[row][col]=-1;
  }

  vector < vector <bool> > visited_copy=visited;
  visited_copy[row][col]=true;

  int sub_value;
  sub_value=cell_value(letter_to_number(cells[row][col][0]),cells[row][col][1]-'0',visited_copy);
  if (sub_value==-1) {
    return cell_values[row][col]=-1;
  }
  else {
    cell_values[row][col]+=sub_value;
  }

  for (int i=3; i<=cells[row][col].length()-2; i+=3) {
    int sub_value;
    sub_value=cell_value(letter_to_number(cells[row][col][i]),cells[row][col][i+1]-'0',visited_copy);
    if (sub_value==-1) {
      return cell_values[row][col]=-1;
    }
    else {
      cell_values[row][col]+=sub_value;
    }
  }

  calculated_cell_values[row][col]=true;
  return cell_values[row][col];

}

int letter_to_number(char c) {
  if (c=='A') {
    return 1;
  }
  if (c=='B') {
    return 2;
  }
  if (c=='C') {
    return 3;
  }
  if (c=='D') {
    return 4;
  }
  if (c=='E') {
    return 5;
  }
  if (c=='F') {
    return 6;
  }
  if (c=='G') {
    return 7;
  }
  if (c=='H') {
    return 8;
  }
  if (c=='I') {
    return 9;
  }
  if (c=='J') {
    return 10;
  }
}