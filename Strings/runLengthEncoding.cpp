using namespace std;
#include <vector>

// O(n) time | O(n) space
string runLengthEncoding(string str) {
  // Write your code here.
  vector<char> encodedStringCharacters = {};
  int currentRunLength = 1;

  for (int i = 1; i < str.size(); i++) {
    char currentCharacter = str[i];
    char previousCharacter = str[i - 1];

    if (currentCharacter != previousCharacter || currentRunLength == 9) {
      encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
      encodedStringCharacters.push_back(previousCharacter);
      currentRunLength = 0;
    }

    currentRunLength++;
  }

  encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
  encodedStringCharacters.push_back(str[str.length() - 1]);
  return string(encodedStringCharacters.begin(), encodedStringCharacters.end());
}