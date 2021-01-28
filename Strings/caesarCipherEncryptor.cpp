using namespace std;
#include <vector>

// O(n) time | O(n) space
string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  key = key % 26;
  vector<char> coded = {};
  for (int i = 0; i < str.length(); i++) {
    char letter = str[i];
    if (letter + key <= 122) {
      coded.push_back(letter + key);
    } else {
      coded.push_back((96 + letter + key) % 122);
    }
  }
  return string(coded.begin(), coded.end());
}

// =========================================================================

using namespace std;
#include <vector>

// O(n) time | O(n) space
string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  key = key % 26;
  vector<char> coded = {};
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < str.length(); i++) {
    char letter = str[i];
    if (alphabet.find(letter) + key > 25) {
      coded.push_back(alphabet[(alphabet.find(letter) + key) % 26]);
    } else {
      coded.push_back(alphabet[alphabet.find(str[i]) + key]);
    }
  }
  return string(coded.begin(), coded.end());
}
