using namespace std;
#include <vector>

// O(n^2) time | O(n) space
bool isPalindrome(string str) {
  // Write your code here.
  string reversedString = "";
  for (int i = str.length() - 1; i >= 0; i--) {
    reversedString += str[i];
  }
  return str == reversedString;
}

// ==============================================================================================================

using namespace std;
#include <vector>

// O(n) time | O(n) space
bool isPalindrome(string str) {
  // Write your code here.
  vector<char> reversedChars = {};
  for (int i = str.length() - 1; i >= 0; i--) {
    reversedChars.push_back(str[i]);
  }
  return str == string(reversedChars.begin(), reversedChars.end());
}

// ==============================================================================================================

// Recursive Solution
using namespace std;
#include <vector>

// O(n) time | O(n) space
bool helper(string str, int i);

bool isPalindrome(string str) { return helper(str, 0); }

bool helper(string str, int i) {
  int j = str.length() - 1 - i;
  return i >= j ? true : str[i] == str[j] && helper(str, i + 1);
}

// ==============================================================================================================

using namespace std;
#include <vector>

// O(n) time | O(1) space
bool isPalindrome(string str) {
  // Write your code here.
  int left = 0;
  int right = str.length() - 1;
  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}