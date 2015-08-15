#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int c = 0;
  int total = 0;
  double temp = 0;
  // Getting the total of the months.
  for (c = 0; c < 12; c++) {
    cin >> temp;
    total += temp*100;
  }

  total = floor(total / 12.00 + 0.5);
  cout << "$" << total / 100.00 << endl;
  return 0;
}

