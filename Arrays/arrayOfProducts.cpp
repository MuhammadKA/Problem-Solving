#include <vector>
using namespace std;

// O(n^2) time | O(n) space
vector<int> arrayOfProducts(vector<int> array) {
  vector<int> products(array.size());

  for (int i = 0; i < array.size(); i++) {
    int runningProduct = 1;
    for (int j = 0; j < array.size(); j++) {
      if (i != j) {
        runningProduct *= array[j];
      }
      products[i] = runningProduct;
    }
  }
  return products;
}

// ------------------------ < Optimal Solution > ---------------

#include <vector>
using namespace std;

// O(n) time | O(n) space
vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
  vector<int> products(array.size(), 1);
  vector<int> leftProducts(array.size(), 1);
  vector<int> rightProducts(array.size(), 1);

  int leftRunningProduct = 1;
  for (int i = 0; i < array.size(); i++) {
    leftProducts[i] = leftRunningProduct;
    leftRunningProduct *= array[i];
  }

  int rightRunningProduct = 1;
  for (int i = array.size() - 1; i >= 0; i--) {
    rightProducts[i] *= rightRunningProduct;
    rightRunningProduct *= array[i];
  }

  for (int i = 0; i < array.size(); i++) {
    products[i] = rightProducts[i] * leftProducts[i];
  }

  return products;
}

// ------------------------ < Cleaner Solution > ---------------

#include <vector>
using namespace std;

// O(n) time | O(n) space
vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
  vector<int> products = {};

  int leftRunningProduct = 1;
  for (int i = 0; i < array.size(); i++) {
    products.push_back(leftRunningProduct);
    leftRunningProduct *= array[i];
  }

  int rightRunningProduct = 1;
  for (int i = array.size() - 1; i >= 0; i--) {
    products[i] *= rightRunningProduct;
    rightRunningProduct *= array[i];
  }

  return products;
}
