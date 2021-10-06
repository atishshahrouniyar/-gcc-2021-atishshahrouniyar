#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int UF_root(int x, vector<int>& arr)
{
    while (x != arr[x])
        x = arr[x];
    return x;
}

void theHackathon(int n, int m, int a, int b, int f, int s, int t) {
    vector<int> arr(n);
    vector<vector<int>> size(4, vector<int> (n));
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
        size[0][i] = 1;
    }
    unordered_map<string, int> corresponding;
    unordered_map<int, string> corr;
    string str, str1;
    int num, max_size=0;
    for (int i = 0; i < n; ++i) {
        cin >> str >> num;
        corresponding[str] = i;
        corr[i] = str;
        size[num][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> str >> str1;
        int root_x = UF_root(corresponding[str], arr);
        int root_y = UF_root(corresponding[str1], arr);
        if (root_x == root_y || size[0][root_x]+size[0][root_y]>b || size[1][root_x]+ size[1][root_y] > f || size[2][root_x] + size[2][root_y] > s || size[3][root_x] + size[3][root_y] > t)
            continue;
        if (size[0][root_x] < size[0][root_y])
        {
            arr[root_x] = arr[root_y];
            size[0][root_y] += size[0][root_x];
            max_size = max(max_size, size[0][root_y]);
            size[1][root_y] += size[1][root_x];
            size[2][root_y] += size[2][root_x];
            size[3][root_y] += size[3][root_x];
        }
        else
        {
            arr[root_y] = arr[root_x];
            size[0][root_x] += size[0][root_y];
            max_size = max(max_size, size[0][root_x]);
            size[1][root_x] += size[1][root_y];
            size[2][root_x] += size[2][root_y];
            size[3][root_x] += size[3][root_y];
        }
    }
    if (max_size < a)
        cout << "no groups" << endl;
    else {
        set<string> answers;
        for (int i = 0; i < n; ++i) {
            if (size[0][UF_root(i, arr)] == max_size)
                answers.insert(corr[i]);
        }
        for (string x : answers)
            cout << x << endl;
    }
}

int main()
{
    string inputdata_temp;
    getline(cin, inputdata_temp);

    vector<string> inputdata = split_string(inputdata_temp);

    int n = stoi(inputdata[0]);

    int m = stoi(inputdata[1]);

    int a = stoi(inputdata[2]);

    int b = stoi(inputdata[3]);

    int f = stoi(inputdata[4]);

    int s = stoi(inputdata[5]);

    int t = stoi(inputdata[6]);

    theHackathon(n, m, a, b, f, s, t);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
