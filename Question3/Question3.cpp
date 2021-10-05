#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    int i, temp;
    for (i = 1; i < a.size() && i < b.size(); ++i) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    for (; i < a.size(); ++i)
        a[i] += a[i - 1];
    for (; i < b.size(); ++i)
        b[i] += b[i - 1];
    int answer = upper_bound(b.begin(), b.end(), maxSum) - b.begin(), n = upper_bound(a.begin(), a.end(), maxSum) - a.begin();
    for (int i = 0; i < n; ++i) {
        temp = i + 1 + upper_bound(b.begin(), b.end(), maxSum - a[i]) - b.begin();
        answer = max(answer, temp);
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}