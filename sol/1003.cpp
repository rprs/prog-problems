// General Election
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;


int main() {
  // get number of cases.
  int cases = 0;
  cin >> cases;
  
  while( cases > 0) {
    
    // get number of rows and cols
    int rows, cols;
    cin >> cols >> rows;
    int candidates[cols];
    
    for (int c = 0; c < cols; c++) {
      candidates[c] = 0;
    }
    
    int temp;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cin >> temp;
       // cout << temp << endl;
        candidates[j] += temp;
      }
    }
    
    int winner = 0;
    for (int c = 0; c < cols; c++) {
      //cout << "total votes: " << candidates[c] << endl;
      if (candidates[c] > candidates[winner]) {
        winner = c;
      }
    }

    cout << winner + 1 << endl;
    cases--;
  }

  // iterate through rows and cols to get totals
  // print colum winner.
  return 0;
}

