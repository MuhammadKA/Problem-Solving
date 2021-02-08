using namespace std;

// Iterative solution
// O(n) time | O(n) space - where n is the total number of elements in the array
vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
  if (array.size() == 0)
    return {};

  // Bounderies of our shape
  vector<int> result = {};
  int startRow = 0;
  int endRow = array.size() - 1;
  int startCol = 0;
  int endCol = array[0].size() - 1;

  while (startCol <= endCol && startRow <= endRow) {
    // iterating over the upper side
    for (int col = startCol; col <= endCol; col++) {
      result.push_back(array[startRow][col]);
    }

    // iterating over the right side
    for (int row = startRow + 1; row <= endRow; row++) {
      result.push_back(array[row][endCol]);
    }

    // iterating over the buttom side
    for (int col = endCol - 1; col >= startCol; col--) {
      // Handle the edge case when there's a single row
      // in the middle of the matrix. In this case, we don't
      // want to double-count the values in this row, which we've
      // already counted in the first for loop above.
      if (startRow == endRow)
        break;
      result.push_back(array[endRow][col]);
    }

    // iterating over the left side
    for (int row = endRow - 1; row > startRow; row--) {
      // Handle the edge case when there's a single column
      // in the middle of the matrix. In this case, we don't
      // want to double-count the values in this column, which we've
      // already counted in the second for loop above.
      if (startCol == endCol)
        break;
      result.push_back(array[row][startCol]);
    }
    startRow++;
    endRow--;
    startCol++;
    endCol--;
  }
  return result;
}

// --------------------------------------------- < Another Solution > -----------------------------------------------

using namespace std;
// Recursive solution
// O(n) time | O(n) space - where n is the total number of elements in the array
void spiralFill(vector<int> &result, vector<vector<int>> &array, int startRow,
                int startCol, int endRow, int endCol);

vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
  if (array.size() == 0)
    return {};

  vector<int> result = {};
  spiralFill(result, array, 0, 0, array.size() - 1, array[0].size() - 1);
  return result;
}

void spiralFill(vector<int> &result, vector<vector<int>> &array, int startRow,
                int startCol, int endRow, int endCol) {

  if (startCol > endCol || startRow > endRow)
    return;

  for (int col = startCol; col <= endCol; col++) {
    result.push_back(array[startRow][col]);
  }

  // iterating over the right side
  for (int row = startRow + 1; row <= endRow; row++) {
    result.push_back(array[row][endCol]);
  }

  // iterating over the buttom side
  for (int col = endCol - 1; col >= startCol; col--) {
    if (startRow == endRow)
      break;
    result.push_back(array[endRow][col]);
  }

  // iterating over the left side
  for (int row = endRow - 1; row > startRow; row--) {
    if (startCol == endCol)
      break;
    result.push_back(array[row][startCol]);
  }

  return spiralFill(result, array, startRow + 1, startCol + 1, endRow - 1,
                    endCol - 1);
}
