#include <bits/stdc++.h>

using namespace std;
int pos, max_profit, cur_profit, j;

int calculateMaximizedReturns(int n, int k, int d, int m, vector<int> returns) {
	vector<int> status(n, 1);
	for (int a = 0; a < k; ++a) {
		pos = -1;
		max_profit = INT_MIN;
		for (int i = 0; i < n; ++i) {
			cur_profit = 0;
			if (status[i] == 0)
				continue;
			if (status[i] == 1) {
				j = i + 1;
				while (j <= i + d && j < n && status[j]) {
					cur_profit += returns[j];
					++j;
				}
				cur_profit *= m - 1;
				cur_profit -= returns[i];
			}
			else {
				j = i + 1;
				while (j <= i + d && j < n && status[j] == 2) {
					++j;
					continue;
				}
				while (j <= i + d && j < n) {
					cur_profit += returns[j];
					++j;
				}
				cur_profit *= m - 1;
				cur_profit -= returns[i] * m;
			}
			if (cur_profit > max_profit) {
				pos = i;
				max_profit = cur_profit;
			}
		}
		status[pos] = 0;
		j = pos + 1;
		while (j <= pos + d && j < n && status[j]) {
			status[j] = 2;
			++j;
		}
	}
	max_profit = 0;
	for (int i = 0; i < n; ++i) {
		if (status[i] == 1)
			max_profit += returns[i];
		else if (status[i] == 2)
			max_profit += m * returns[i];
	}
	return max_profit;
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

vector<int> splitStringToInt(const string& str, char delim) {
    vector<int> strings;
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

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int n = firstLineVec[0];
    int k = firstLineVec[1];
    int d = firstLineVec[2];
    int m = firstLineVec[3];

    string returns;
    getline(cin, returns);

    vector<int> returnsVec = splitStringToInt(returns, ' ');

    int result = calculateMaximizedReturns(n, k, d, m, returnsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}