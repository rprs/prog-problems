
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int StringToNumber() {
  string input;
  getline(cin, input);
  stringstream ss;
  ss << input;
  int result;
  return ss >> result ? result : -1;
}



int main () {
  int numPairs = 0;
  int numbers,i;
  numbers = StringToNumber();
  while (numbers != -1) {
    int arr[numbers];
    for (i = 0; i < numbers; i++) {
      cin >> arr[i];
    }
    int elements = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + elements);
    int temp = -1;
    numPairs = 0;
    for (i = 0; i < numbers; i ++) {
      if(temp == arr[i]) {
        numPairs++;
        temp = -1;
      } else {
        temp = arr[i];
      }
    }
    int result = numPairs / 2; 
    cout << result << endl;
    string waste;
    getline(cin, waste);
    numbers = StringToNumber();
  }
  return 0;
}

