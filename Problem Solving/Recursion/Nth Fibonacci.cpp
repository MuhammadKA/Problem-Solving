// Solution 1
using namespace std;

// O(2^n) time | O(n) space
int getNthFib(int n) {
  // Write your code here.
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  return getNthFib(n - 1) + getNthFib(n - 2);
}

//************************************************************************************************************

// Solution 2 (Using Tabulation)
using namespace std;
#include <vector>

// O(n) time | O(n) space
int getNthFib(int n) {
  // Write your code here.
  std::vector<int> table(n);
  table[0] = 0;
  table[1] = 1;
  for (int i = 0; i < n; i++) {
    if (i + 1 < n)
      table[i + 1] += table[i];
    if (i + 2 < n)
      table[i + 2] += table[i];
  }
  return table[n - 1];
}

//************************************************************************************************************

// Solution 3 (Using Memoization)
using namespace std;
#include <unordered_map>

// O(n) time | O(n) space
int getNthFib(int n);
int helper(int n, unordered_map<int, int> &memoize);

// O(n) time | O(n) space
int getNthFib(int n) {
  unordered_map<int, int> memoize({{1, 0}, {2, 1}});
  return helper(n, memoize);
}

int helper(int n, unordered_map<int, int> &memoize) {
  if (memoize.find(n) != memoize.end()) {
    return memoize[n];
  } else {
    memoize[n] = helper(n - 1, memoize) + helper(n - 2, memoize);
    return memoize[n];
  }
}

//************************************************************************************************************

// Solution 4
using namespace std;

// O(n) time | O(1) space
int getNthFib(int n) {
  // Write your code here.
  std::vector<int> lastTwo = {0, 1};
  if (n == 1)
    return lastTwo[0];
  if (n == 2)
    return lastTwo[1];
  int counter = 2;
  while (counter < n) {
    int temp = lastTwo[0] + lastTwo[1];
    lastTwo[0] = lastTwo[1];
    lastTwo[1] = temp;
    counter++;
  }
  return lastTwo[1];
}

//################################################## << Dynamic Programming FreeCodeCamp.com >> ################################################

#include <iostream>
#include <map>
#include <vector>
//  *** Using Brute Force ***
// Time complexity O(2^n)
// Space complexity O(n)
int fib_BF(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  return fib_BF(n - 1) + fib_BF(n - 2);
}

//  *** Using Memoization ***
// Time complexity O(n)
// Space complexity O(n)
long fib_Mem(int n) {

  static std::map<long long, long> memo;

  if (memo.find(n) != memo.end())
    return memo[n];

  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }

  memo[n] = fib_Mem(n - 1) + fib_Mem(n - 2);
  return memo[n];
}

//  *** Using Tabulation ***
// Time complexity O(n)
// Space complexity O(n)
long fib_Tab(int n) {
  std::vector<long> table(n + 1, 0);
  table[1] = 1;
  for (int i = 0; i <= n; i++) {
    if (i + 1 <= table.size() + 1)
      table[i + 1] += table[i];
    if (i + 2 <= table.size() + 1)
      table[i + 2] += table[i];
  }
  return table[n];
}

int main() {
  std::cout << fib_Tab(6) << std::endl;  // 8
  std::cout << fib_Tab(7) << std::endl;  // 13
  std::cout << fib_Tab(8) << std::endl;  // 21
  std::cout << fib_Tab(50) << std::endl; // 12586269025

  return 0;
}