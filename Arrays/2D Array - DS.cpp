
/*
Given a 6x6 2D Array, :

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
An hourglass in  is a subset of values with indices falling in this pattern in
's graphical representation:

a b c
  d
e f g
There are  hourglasses in . An hourglass sum is the sum of an hourglass' values.
Calculate the hourglass sum for every hourglass in , then print the maximum
hourglass sum. The array will always be .

Example

-9 -9 -9  1 1 1
 0 -9  0  4 3 2
-9 -9 -9  1 2 3
 0  0  8  6 6 0
 0  0  0 -2 0 0
 0  0  1  2 4 0

The  hourglass sums are:

-63, -34, -9, 12,
-10,   0, 28, 23,
-27, -11, -2, 10,
  9,  17, 25, 18

The highest hourglass sum is  from the hourglass beginning at row , column :

0 4 3
  1
8 6 6

*/

#include <bits/stdc++.h>
using namespace std;

// Complete the hourglassSum function below.

int hourglassSum(vector<vector<int>> arr) {
  int height = 5;
  int width = 5;
  int col = 0, row = 0;
  vector<int> result = {};
  int currentSum = 0;
  while (col + 2 <= width && row + 2 <= height) {
    currentSum = arr[row][col] + arr[row][col + 1] + arr[row][col + 2] +
                 arr[row + 1][col + 1] + arr[row + 2][col] +
                 arr[row + 2][col + 1] + arr[row + 2][col + 2];
    std::cout << "row:" << row << " "
              << "col:" << col << " Sum:" << currentSum << std::endl;
    result.push_back(currentSum);
    currentSum = 0;
    col++;
    if (col + 2 > width) {
      col = 0;
      row++;
    }
  }
  int max = *max_element(std::begin(result), std::end(result));
  return max;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      cin >> arr[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = hourglassSum(arr);

  fout << result << "\n";

  fout.close();

  return 0;
}
