// Sum
#include <iostream>
#include <cmath>

using namespace std;

int suma(int n) {
  return n*(n+1)/2 ;
}

int main() {
  int a;
  cin >> a;
  int result;
  if(a < 0) {
    result = ( suma(abs(a)) -1 ) * -1;
  } else {
    result = suma (a);
  }
  cout << result << endl;
  return 0;
}

