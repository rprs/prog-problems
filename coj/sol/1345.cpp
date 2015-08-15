// Brownie Points I
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct point{
 int x;
 int y;
};

int main() {
  
  // Variables
  long x,y;
  long cases;
  long stan, ollie;
  cin >> cases;
  int middle;

  while (cases > 0) {
    // Initializing
    x = 0;
    y = 0;
    point arr[cases];
    middle = (cases / 2);

    // Get points into array. 
    // Save data for oint in the middle of the list.
    for(int i = 0; i < cases; i++) {
      cin >> arr[i].x >> arr[i].y;
      if (i == middle) {
        x = arr[i].x;
        y = arr[i].y;
        // cout << x << " " << y << " is our middle point." << endl;
      }
      // test that I am getting the matrix correctly
      // cout << arr[i].x << "%" << arr[i].y << endl;
    }
    
    // Calculate points for stan and ollie.
    // Stan gets a > x && b > y
    // Stan gets a < x && b < y
    // Ollie get a < x && b < y
    // Ollie get a > x && b > y
    stan = 0;
    ollie = 0;
    for(int i = 0; i < cases; i++) {
      if ((arr[i].x > x && arr[i].y > y) || (arr[i].x < x && arr[i].y < y)) {
        stan++;
        // cout << "(" <<  arr[i].x << " " << arr[i].y << ") goes to Stan" << endl;
      } else if ((arr[i].x < x && arr[i].y > y) || (arr[i].x > x && arr[i].y < y)) {
        ollie++;
        // cout << "(" <<  arr[i].x << " " << arr[i].y << ") goes to Ollie" << endl;
      }
    }

    // Print result and read new cases.
    cout << stan << " " << ollie << endl;
    cin >> cases;
  }
  return 0;
}

