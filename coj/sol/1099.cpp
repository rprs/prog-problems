#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>

using namespace std;

bool isPythagoreanTriplet(int a, int b, int c) {
  return (pow(a, 2) + pow(b,2) == pow(c,2));
}

void swap (int* a, int* b) {
  int* temp;
  temp = a;
  a = b;
  b = temp;
}
    

int main() {
  // Read stdin until line is "0"
  string input;
  int a, b, c;
  getline(cin, input);
  
  while (input.compare("0") != 0)
  {
    // Get values from string "a b c"
    std::istringstream buf(input);
    std::istream_iterator<std::string> beg(buf), end;
    std::vector<std::string> tokens(beg, end);

    stringstream(tokens[0]) >> a;
    stringstream(tokens[1]) >> b;
    stringstream(tokens[2]) >> c;
    
    a = abs(a);
    b = abs(b);
    c = abs(c);

    // Order them.
    if (a > b) {
      swap(a, b);
    }
    if (b > c) {
      swap(b, c);
    }
    if (a > b) {
      swap(a, b);
    }
  
    // put them in the formula
    if (isPythagoreanTriplet(a, b, c)) {
      cout << "right" << endl;
    } else {
      cout << "wrong" << endl;
    }

    getline(cin, input);
  }
  return 0;
}

