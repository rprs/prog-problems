#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string input;
  getline(cin, input);
  int counter = 0;
  std::size_t found;
  string result = "";
  while( input != "") {
    found = input.find("FBI");
    if (found!=std::string::npos) {
      stringstream temp;
      temp << counter + 1;
      result.append(temp.str());
      result.append(" ");
    }
    counter++;
    getline(cin, input);
  }
  result =  (result == "") ? "HE GOT AWAY!" : result.substr(0, result.length() - 1);
  cout << result << endl;
  return 0;
}

