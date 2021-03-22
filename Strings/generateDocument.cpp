using namespace std;
#include <unordered_map>

// O(n + m) time | O(c) space - where n is the number of characters, m is the
// length of the document, and c is the number of unique characters in the
// characters string
bool generateDocument(string characters, string document) {
  // Write your code here.
  unordered_map<char, int> memo;
  for (char character : characters) {
    if (memo.find(character) == memo.end()) {
      memo[character] = 1;
    } else {
      memo[character] += 1;
    }
  }

  for (int i = 0; i < document.length(); i++) {
    char currentChar = document[i];
    if (memo.find(currentChar) == memo.end() || memo[currentChar] == 0) {
      return false;
    } else {
      memo[currentChar] -= 1;
    }
  }
  return true;
}
