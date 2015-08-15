#include <iostream>

using namespace std;

/* Gets the minimum value of the cells:
 * - above this one.
 * - left of this one.
 * - above left of this one.
 * order does not matter
 */
int getMinimumvalue(int **inLand, int x, int y) {
  // Getting cell left.
  int result = inLand[x -1][y];
  
  // Getting cell above left.
  int temp = inLand[x - 1][y - 1];
  result = (result > temp) ? temp : result;

  // Getting cell above.
  temp = inLand[x][y - 1];
  result = (result > temp) ? temp : result;

  return result;
}


int main() {

  int cases, length, max;
  char c;
  // Read number of cases.
  cin >> cases;

  while (cases > 0) {
    // Read size of the square.
    cin >> length;
    max = 0;
    int **land;
    land = new int *[length];
    for (int i = 0; i < length; i++) {
      land[i] = new int[length];
      for (int j = 0; j < length; j++) {
        // get the '.' or the '#'.        
        cin >> c;
        if (c == '#') {
          // If obstacle, no part of a square.
          land[i][j] = 0;
        } else if ( i == 0 || j == 0 ) {
          // If on the border, by default is one.
          land[i][j] = 1;
        } else if (i > 0 && j > 0) {
          // The real meat. Get the minimum of the 
          // three upper left cels and add one.
          land[i][j] = getMinimumvalue(land, i, j) + 1;
          if (land[i][j] > max) {
            max = land[i][j];
          }
        } 
      }
    }
    cout << max << endl;
    cases--;
  }
  return 0;
}

