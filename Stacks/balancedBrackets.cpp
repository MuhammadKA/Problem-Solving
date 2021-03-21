using namespace std;
#include <stack>
#include <unordered_map>

// O(n) time | O(n) space
bool balancedBrackets(string str) {
  stack<char> stack;
  string openingBrackets = "({[";
  string closingBrackets = ")}]";
  unordered_map<char, char> matchingBrackets{
      {']', '['}, {'}', '{'}, {')', '('}};
  for (char character : str) {
    if (openingBrackets.find(character) != string::npos) {
      stack.push(character);
    } else if (closingBrackets.find(character) != string::npos) {
      if (stack.size() == 0)
        return false;
      if (stack.top() == matchingBrackets[character])
        stack.pop();
      else
        return false;
    }
  }
  return stack.size() == 0;
}

/*
Here we have 3 corner cases to return false:
1- When we have a closing bracket but the stack doesn't contain any opening brackets
2- When we have a closing bracket that doesn't match the opening bracket on the top of the stack
3- When we finish traversing the whole string and we still have un popped opening brackets on the stack
*/
