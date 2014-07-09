// Ball Stacking
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
  int height;
  long maxSum, current;
  cin >> height;
  while (height > 0) {
    
    current = 0;
    maxSum = 0;
    int i,j;
    // Initialize matrix
    int n = height + 1;
    long matrix[n][n];
    for (i = 0; i < n; i++) {
      for (j = 0; j <= n; j++) {
        matrix[i][j] = 0;
      }
    }
 
    // Make calculations. sum[i][j] = sum[i-1][j-1] + sum[i-1][j] + current;
    for (i = 1; i < n; i++) {
      for (j = 1; j <= i; j++) {
        cin >> current;
        matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j] + current;
        // matrix[i][j] = current;
        if (maxSum < matrix[i][j]) {
          maxSum = matrix[i][j];
        }
      }
    }
 
    // Printing matrix for testing purposes
    /*for (i = 1; i < n; i++) {
      for (j = 1; j <= i; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }*/
    
    if (maxSum != 0) {
      maxSum++;
    }
    cout << maxSum << endl;
    cin >> height;
  }
 
  return 0;
}
