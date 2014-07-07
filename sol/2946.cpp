// Inverting the Parity 
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
  unsigned long times, current;
  cin >> times;
  while (times > 0) {
    cin >> current;
    times--;
    if (current % 2 != 0) {
      current = current << 1;
    } else {
      while(current % 2 == 0) {
        current = current >> 1;
      }
    }
    cout << current << endl;
  }
  return 0;
}

