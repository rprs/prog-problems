// Trisum
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
  unsigned long a0, b0, c0, an, bn, cn;
  unsigned long level = 0;
  cin >> level >> a0 >> b0 >> c0;
  an = a0;
  bn = b0;
  cn = c0;
  while (level > 0) {
    an = (3 * (b0 + c0))%10007;
    bn = (3 * (a0 + c0))%10007;
    cn = (3 * (b0 + a0))%10007;
    a0 = an;
    b0 = bn;
    c0 = cn;
    level--;
  }
  cout << an << " " << bn << " " << cn << endl;
  return 0;
}

