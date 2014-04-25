#include <iostream>

using namespace std;

int main() {
  int rows, cols;
  cin >> rows >> cols;
  //O I E
  string gift = "OIE";
  int i,j;
  int index = 0;
  for (i = 0; i < rows; i++) {
    index = i % 3;
    for (j = 0; j < cols; j++) {
      cout << gift[index++];
      index = index % 3;
    }
    cout << endl;
  }
  return 0;
}

