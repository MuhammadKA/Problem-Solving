using namespace std;
#include <unordered_map>

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
  vector<int> stack = {};
  vector<unordered_map<string, int>> minMaxStack = {};

  // O(1) time | O(1) space
  int peek() { return stack[stack.size() - 1]; }

  // O(1) time | O(1) space
  int pop() {
    int value = stack[stack.size() - 1];
    stack.pop_back();
    minMaxStack.pop_back();
    return value;
  }

  // O(1) time | O(1) space
  void push(int number) {
    unordered_map<string, int> newMinMax = {{"min", number}, {"max", number}};
    if (!minMaxStack.empty()) {
      unordered_map lastMinMax = minMaxStack[minMaxStack.size() - 1];
      newMinMax["min"] = min(newMinMax["min"], lastMinMax["min"]);
      newMinMax["max"] = max(newMinMax["max"], lastMinMax["max"]);
    }
    stack.push_back(number);
    minMaxStack.push_back(newMinMax);
  }

  // O(1) time | O(1) space
  int getMin() { return minMaxStack[stack.size() - 1]["min"]; }

  // O(1) time | O(1) space
  int getMax() { return minMaxStack[stack.size() - 1]["max"]; }
};
