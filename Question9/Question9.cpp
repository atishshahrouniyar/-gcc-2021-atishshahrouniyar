#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int bankersAndClients(int c, int b, vector< vector<int> >& time) {
    int max_power = 1 << b, answer = INT_MAX;
    int dp[c][b][max_power];
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < max_power; ++k)
                dp[i][j][k] = INT_MAX;
        }
    }
    for (int i = 0; i < b; ++i) {
        dp[0][i][1 << i] = time[i][0];
    }
    for (int i = 0; i < c - 1; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < max_power; ++k) {
                if (dp[i][j][k] != INT_MAX) {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + time[j][i + 1]);
                    for (int l = 0; l < b; ++l) {
                        if (!(k & (1 << l))) {
                            dp[i + 1][l][k | (1 << l)] = min(dp[i + 1][l][k | (1 << l)], dp[i][j][k] + time[l][i + 1]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < max_power; ++j) {
            answer = min(answer, dp[c - 1][i][j]);
        }
    }
    return answer;
}

int main() {
    int b, c;
    cin >> c >> b;
    int answer;
    vector<vector<int>> time(b, vector<int>(c));
    for (int i = 0; i < b; i++) {

        for (int j = 0; j < c; j++) {
            cin >> time[i][j];
        }
    }
    answer = bankersAndClients(c, b, time);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
