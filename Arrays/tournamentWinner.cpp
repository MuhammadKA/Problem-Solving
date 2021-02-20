#include <unordered_map>
#include <vector>
using namespace std;

const int HOME_TEAM_WON = 1;

// O(n) time | O(k) space - k is the number of teams
void updateScores(string team, int points, unordered_map<string, int> &scores);

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
  string currentBestTeam = "";
  unordered_map<string, int> scores = {{currentBestTeam, 0}};

  for (int i = 0; i < results.size(); i++) {
    int result = results[i];
    string homeTeam = competitions[i][0];
    string awayTeam = competitions[i][1];
    string winningTeam = result == HOME_TEAM_WON ? homeTeam : awayTeam;
    updateScores(winningTeam, 3, scores);

    if (scores[winningTeam] > scores[currentBestTeam])
      currentBestTeam = winningTeam;
  }
  return currentBestTeam;
}

void updateScores(string team, int points, unordered_map<string, int> &scores) {
  if (scores.find(team) == scores.end())
    scores[team] = 0;
  scores[team] += points;
}
