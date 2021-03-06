#include <vector>

using namespace std;

// O(n) time | O(n) space
bool isOutOfBound(int height, int width, int row, int col);

vector<int> zigzagTraverse(vector<vector<int>> array) {
  // Write your code here.
  int height = array.size() - 1;
  int width = array[0].size() - 1;
  int col = 0, row = 0;
  bool goingDown = true;
  vector<int> result = {};
  while (!isOutOfBound(height, width, row, col)) {
    result.push_back(array[row][col]);
    if (goingDown) {
      if (col == 0 || row == height) {
        goingDown = false;
        if (row == height) {
          col++;
        } else {
          row++;
        }
      } else {
        row++;
        col--;
      }
    } else {
      if (row == 0 || col == width) {
        goingDown = true;
        if (col == width) {
          row++;
        } else {
          col++;
        }
      } else {
        row--;
        col++;
      }
    }
  }
  return result;
}

bool isOutOfBound(int height, int width, int row, int col) {
  return row < 0 || row > height || col < 0 || col > width;
}