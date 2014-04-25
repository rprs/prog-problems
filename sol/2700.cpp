#include <iostream>
#include <string>

using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  int i  = 0;
  int j = 0;
  string first = "";
  string second = "";
  string both = "";
  int temp;
  while (i < a.length() && j < b.length()) {
    temp = a[i] - b[j];
    if (temp > 0) {
      second += b[j++];
    } else if (temp < 0) {
      first += a[i++];
    } else {
      both += a[i++];
      j++;
    }
  }
  if (i < a.length()) {
    first.append(a.substr(i));
  }
  if (j < b.length()) {
    second.append(b.substr(j));
  }


  cout << "First:" << first << endl;
  cout << "Second:" << second << endl;
  cout << "First&Second:" << both << endl;
  return 0;
}

