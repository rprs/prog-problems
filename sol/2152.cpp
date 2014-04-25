#include <iostream>

using namespace std;

int main() {
  int total, cases;
  string input;
  cin >> cases;
  getline (cin, input);
  while (cases > 0) {
    total = 0;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++ ) {
      char c = input[i];
      if (c != '-') {
        total += c - 48;
      }
    }
    cout << total << endl;
    cases--;
  }
  return 0;
}

