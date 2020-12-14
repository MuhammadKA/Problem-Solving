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

// Using Tabulation

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