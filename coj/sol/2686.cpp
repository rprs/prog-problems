// Helping Nolberto
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <locale>

using namespace std;

int main() {

  // variables.
  int lines;
  cin >> lines;
  string line, word;
  getline(cin, line);
  bool first = true;
  int i,j;
  while (lines > 0 ) {
    getline(cin, line);
    i = 0;
    while (i < line.size()) {
      char c = line[i];
      if (line[i] == 's' || line[i] == 'S') {
        j = i;
        while (line[j] == 's' || line[j] == 'S') {
          j++;
        }
        if (line[j] == ' ' || j == line.size()) {
          i = j;
        }
      }
      
      if (i < line.size()) {
        cout << (char) std::toupper(line[i]);
      }
      i++;
    }
    cout << endl;
    lines--;
  }
  return 0;
}

