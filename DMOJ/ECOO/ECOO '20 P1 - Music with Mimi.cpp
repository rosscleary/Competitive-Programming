#include <bits/stdc++.h>
using namespace std;

const string all_notes[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

int T;

void shift(int note_places[4]) {
  int new_note_places[4];
  for(int i = 0; i < 3; i++) new_note_places[i + 1] = note_places[i];
  new_note_places[0] = note_places[3];
  for(int i = 0; i < 4; i++) note_places[i] = new_note_places[i];
}

void find_diffs(int diffs[3], int note_places[4]) {
  for(int i = 0; i < 3; i++) {
    if(note_places[i + 1] < note_places[i]) diffs[i] = (11 - note_places[i]) + note_places[i + 1] + 1;
    else diffs[i] = note_places[i + 1] - note_places[i];
  }
}

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> T;

  while(T--) {
    string notes[4];
    int note_places[4];
    int diffs[3];

    cin >> notes[0] >> notes[1] >> notes[2] >> notes[3];

    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 12; j++) {
        if(notes[i] == all_notes[j]) {
          note_places[i] = j;
          break;
        }
      }
    }

    find_diffs(diffs, note_places);
    if(diffs[0] == 4 && diffs[1] == 3 && diffs[2] == 3) {
      cout << "root\n";
      continue;
    }
    shift(note_places);
    find_diffs(diffs, note_places);
    if(diffs[0] == 4 && diffs[1] == 3 && diffs[2] == 3) {
      cout << "first\n";
      continue;
    }
    shift(note_places);
    find_diffs(diffs, note_places);
    if(diffs[0] == 4 && diffs[1] == 3 && diffs[2] == 3) {
      cout << "second\n";
      continue;
    }
    shift(note_places);
    find_diffs(diffs, note_places);
    if(diffs[0] == 4 && diffs[1] == 3 && diffs[2] == 3) {
      cout << "third\n";
      continue;
    }
    cout << "invalid\n";
  }

  return 0;
}