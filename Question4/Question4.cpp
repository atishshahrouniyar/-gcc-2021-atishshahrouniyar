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
int totalPairs(int n, vector<int>& values) {
    int answer = n-1;
    stack<int> s;
    s.push(values[0]);
    for (int i = 1; i < n; ++i) {
        if (values[i] > values[i - 1]) {
            s.pop();
            while (!s.empty() && s.top() <= values[i]) {
                s.pop();
                ++answer;
            }
            if (!s.empty())
                ++answer;
        }
        s.push(values[i]);
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
