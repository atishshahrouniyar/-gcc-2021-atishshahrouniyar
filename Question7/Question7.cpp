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

const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;
int smallest_prime_factor[MAX], arr[MAX], sizes[MAX];
bool final_sizes[MAX];

using namespace std;

int UF_root(int x)
{
    while (x != arr[x])
        x = arr[x];
    return x;
}

void UF_union(int x, int y)
{
    int root_x = UF_root(x);
    int root_y = UF_root(y);
    if (root_x == root_y)
        return;
    if (sizes[root_x] < sizes[root_y])
    {
        arr[root_x] = arr[root_y];
        sizes[root_y] += sizes[root_x];
    }
    else
    {
        arr[root_y] = arr[root_x];
        sizes[root_x] += sizes[root_y];
    }
}

void countStablePartitions(int n, vector<int>& values) {
    final_sizes[0] = false;
    for (int i = 1; i < MAX; ++i) {
        smallest_prime_factor[i] = i;
        arr[i] = i;
        sizes[i] = 1;
        final_sizes[i] = false;
    }
    for (int i = 4; i < MAX; i += 2)
        smallest_prime_factor[i] = 2;
    for (int i = 3; i * i < MAX; ++i) {
        if (smallest_prime_factor[i] == i) {
            for (int j = i * i; j < MAX; j += i)
                if (smallest_prime_factor[j] == j)
                    smallest_prime_factor[j] = i;
        }
    }
    long long a, temp;
    for (int i = 0; i < n; ++i) {
        temp = values[i];
        while (true) {
            a = smallest_prime_factor[temp];
            temp /= a;
            if (smallest_prime_factor[temp] == 1)
                break;
            else
                UF_union(a, smallest_prime_factor[temp]);
        }
    }
    for (int i = 0; i < n; ++i) {
        final_sizes[UF_root(smallest_prime_factor[values[i]])] = true;
    }
    long long count = accumulate(final_sizes, final_sizes + MAX, 0), x = 2;
    if (count == 1) {
        cout << "NO" << endl << 0 << endl;
        return;
    }
    a = 1;
    while (count) {
        if (count & 1)
            a = (a * x) % MOD;
        x = (x * x) % MOD;
        count >>= 1;
    }
    a = (a + MOD - 2) % MOD;
    cout << "YES" << endl << a << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    countStablePartitions(n, values);
    return 0;
}
