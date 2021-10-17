#include <bits/stdc++.h>

using namespace std;

long long calculateMaximizedReturns(int n, int k, int d, long long m, vector<long long> returns) {
    long long pos, profit, current;
    vector<long long> status(n, 1);
    for (int i = 0; i < k; ++i) {
        pos = -1; profit = INT_MIN;
        for (int j = 0; j < n; ++j) {
            if (status[j]) {
                current = (-1) * status[j] * returns[j];
                for (int k = j + 1; k <= j + d && k<n; ++k) {
                    if (!status[k]) {
                        break;
                    }
                    else if (status[k] == 1) {
                        current += (m - 1) * returns[k];
                    }
                }
            }
            if (current > profit) {
                profit = current;
                pos = j;
            }
        }
        status[pos] = 0;
        for (int j = pos + 1; j <= pos + d && j < n; ++j) {
            if(status[j])
                status[j] = m;
        }
    }
    profit = 0;
    for (int i = 0; i < n; ++i) {
        profit += status[i] * returns[i];
    }
    return profit;
}

vector<string> split(const string& str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<long long> splitStringToInt(const string& str, char delim) {
    vector<long long> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<long long> firstLineVec = splitStringToInt(firstLine, ' ');
    int n = firstLineVec[0];
    int k = firstLineVec[1];
    int d = firstLineVec[2];
    int m = firstLineVec[3];

    string returns;
    getline(cin, returns);

    vector<long long> returnsVec = splitStringToInt(returns, ' ');

    long long result = calculateMaximizedReturns(n, k, d, m, returnsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}