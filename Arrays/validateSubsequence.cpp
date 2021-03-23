// Solution 1
using namespace std;

// O(n) time | O(1) space
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int ptr_seq = 0;
  int ptr_subseq = 0;
  for (ptr_seq; ptr_seq < array.size(); ptr_seq++) {
    if (array[ptr_seq] == sequence[ptr_subseq]) {
      ptr_subseq++;
    }
    if (ptr_subseq == sequence.size()) {
      return true;
    }
  }
  return false;
}

//*************************************************************************

// Solution 2
using namespace std;

// O(n) time | O(1) space
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  int ptr_seq = 0;
  for (auto value : array) {
    if (sequence[ptr_seq] == value)
      ptr_seq++;
    if (ptr_seq == sequence.size())
      break;
  }
  return ptr_seq == sequence.size();
}
