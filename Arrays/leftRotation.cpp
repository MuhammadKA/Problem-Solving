/*
A left rotation operation on an array shifts each of the array's elements 1 unit
to the left. For example, if  left rotations are performed on array [1, 2, 3, 4, 5], then the
array would become [3, 4, 5, 1, 2]. Note that the lowest index item moves to the highest index
in a rotation. This is called a circular array.

Given an array  of  integers and a number, , perform  left rotations on the
array. Return the updated array to be printed as a single line of
space-separated integers.

Function Description

Complete the function rotLeft in the editor below.

rotLeft has the following parameter(s):

int a[n]: the array to rotate
int d: the number of rotations
Returns

int a'[n]: the rotated array
Input Format

The first line contains two space-separated integers  and , the size of  and the
number of left rotations. The second line contains  space-separated integers,
each an .


*/

#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);

// Complete the rotLeft function below.
// Fails on larger arrays
vector<int> rotLeft(vector<int> a, int d) {
  if (a.size() <= 1)
    return a;
  if (a.size() == 2 && d % 2 == 0)
    return a;
  if (a.size() == 2 && d % 2 != 0) {
    swap(a[0], a[1]);
    return a;
  }

  d = d % a.size();
  for (int i = 0; i < d; i++) {
    int firstElement = a[0];
    int firstPtr = 0;
    int secondPtr = 1;
    while (secondPtr <= a.size()) {
      a[firstPtr] = a[secondPtr];
      firstPtr++;
      secondPtr++;
      if (secondPtr == a.size())
        a[secondPtr] = firstElement;
    }
  }
  return a;
}

// Works all the time - More optimal
vector<int> rotLeft_optimal(vector<int> a, int d) {
  vector<int> first = {};
  vector<int> second = {};
  for (int i = 0; i <= d - 1; i++) {
    first.push_back(a[i]);
  }
  for (int i = d; i < a.size(); i++) {
    second.push_back(a[i]);
  }
  second.insert(second.end(), first.begin(), first.end());
  return second;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  vector<int> result = rotLeft(a, d);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
