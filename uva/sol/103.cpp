#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to know if all dimensions of A are smaller than B.
// This funciton assumes both arrays have been sorted.
bool doesAFitInB(int* a, int* b, int length) {
  for (int i = 0; i < length; i++) {
    // cout << "comparing: " << a[i] << " " << b[i] << endl;
    if (b[i] <= a[i]) {
      return false;
    }
  }
  return true;
}

// Print a std::vector
void printvector(std::vector<int> L) {
  std::vector<int>::iterator it;
  for (it = L.begin(); it != L.end(); it++) {
    cout << *it + 1;
    if (*it != L.back()) {
      cout << " ";
    }
  }
  cout << endl;
}


std::vector<int> **vectorarr;

// Gets longest path of boxes that fit.
std::vector<int> getLongestPath(int n, std::vector<int> L) {
  std::vector<int> currL = L;
  currL.push_back(n);
  if (vectorarr[n]->size() == 0) {
    return currL;
  } else {
    std::vector<int> maxL = currL;
    std::vector<int>::iterator it;
    std::vector<int> tempL;
    for (it = vectorarr[n]->begin(); it != vectorarr[n]->end(); it++) {
      tempL = getLongestPath(*it, currL);
      if (tempL.size() > maxL.size()) {
        maxL = tempL;
      }
    }
    return maxL;
  }
}



int main() {

  // Get Data.
  int boxes, dimensions;
  while (cin >> boxes >> dimensions) {
    int **boxarr;
    boxarr = new int *[boxes];
    for (int i = 0; i < boxes; i++) {
      boxarr[i] = new int[dimensions];
      for (int j = 0; j < dimensions; j++) {
        cin >> boxarr[i][j];
      }
    }

    // Sort arrays.
    for (int i = 0; i < boxes; i++) {
      sort(boxarr[i], boxarr[i] + dimensions);
    }

    // Getting vectors for the boxes which will fit each box.
    vectorarr = new std::vector<int> *[boxes];
    for (int i = 0; i < boxes; i++) {
      vectorarr[i] = new std::vector<int>;
      for (int j = 0; j < boxes; j++) {
        // cout << "checking if " << i << " fits in " << j << endl;
        if (doesAFitInB(boxarr[i], boxarr[j], dimensions)) {
          // cout << i << " fits in " << j << endl;
          vectorarr[i]->push_back(j);
        }
      }
    }    

    /*
    cout << "vector of boxes each box fit in" << endl;
    for (int i = 0; i < boxes; i++) {
      cout << i << ":";
      std::vector<int>::iterator it;
      std::vector<int> tempL;
      for (it = vectorarr[i]->begin(); it != vectorarr[i]->end(); it++) {
        cout << " " << *it;
      }
      cout << endl;
    }
    */

    // GetLongestPath for each box.
    std::vector<int> tempvector;
    std::vector<int> currL;
    std::vector<int> maxL;
    for (int i = 0; i < boxes; i++) {
      currL = getLongestPath(i, tempvector);
      if (currL.size() > maxL.size()) {
        maxL = currL;
      }
    }

    // Printing result.
    cout << maxL.size() << endl;
    printvector(maxL);

      // TEST: print arrays.
      /*
         cout << "boxes and dimensions:";
         cout << boxes << " " << dimensions << endl;
         cout << "boxes:" << endl;
         for (int i = 0; i < boxes; i++) {
         for (int j = 0; j < dimensions; j++) {
         cout << boxarr[i][j] << " ";
         }
         cout << endl;
         }
         */
  }
  return 0;
}
