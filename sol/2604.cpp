// Arithmetic with Morse
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int sumNumber(std::string input, std::string::size_type* index) {
  map<char, int> dict;
  dict['.'] = 1;
  dict[':'] = 2;
  dict['-'] = 5;
  dict['='] = 10;

  int result = 0;
  
  while(*index < input.size() && input[*index] != ' ') {
    result += dict[input[*index]];
    (*index)++;
  }
  return result;
}



int main() {
  std::string input;
  getline(std::cin, input);
  getline(std::cin, input);
  stack<int> bucket;
  char op;
  int n;
  std::string::size_type i = 0;
  n = sumNumber(input, &i);
  while (i < input.size()) {
    op = input[++i];
    i += 2;
    if (op == '+') {
      bucket.push(n);
      n = sumNumber(input, &i);
    } else if (op == '*') {
      n *= sumNumber(input, &i);
    }
  }
  while (!bucket.empty()) {
    n += bucket.top();
    bucket.pop();
  }
  cout << n << endl;
  return 0;
}

