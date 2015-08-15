// Hidden Candy
// FAIL because I missread the problem.
// I was asked for numbers that had 3 divisors,
// but I returned numvers that are divisible by 3.
// Pooh.
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
  unsigned long a,b,numbers,total;
  int tests;
  cin >> tests;
  while (tests > 0) {
    cin >> a >> b;
    // Testing I can read well.
    // cout << a << " " << b << endl;
    while ( a % 3 != 0 && a < b) {
      a++;
    }
    numbers = b - a + 1;
    total = numbers / 3;
    if (numbers % 3 != 0 && a % 3 == 0) {
      total++;
    }
    cout << total << endl;
    tests--;
  }
  return 0;
}

