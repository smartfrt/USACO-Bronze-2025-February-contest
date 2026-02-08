#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<int> A;

bool allEqual(int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        if (A[i] != A[i - 1]) return false;
    }
    return true;
}

bool checkPattern2(int l, int r) {
    vector<pair<int, int>> blocks;

    for (int i = l; i <= r; i++) {
        if (!blocks.empty() && A[i] == A[i - 1]) {
            blocks.back().second++;
        } else {
            blocks.push_back(pair<int,int>(A[i], 1));
        }
    }

    int sz = blocks.size();

    if (sz <= 2 || sz % 2 == 0) {
        for (int i = 0; i + 2 < sz; i++) {
            if (blocks[i] != blocks[i + 2]) return false;
        }
        return true;
    }

    return false;
}

bool checkPattern3(int l, int r) {
    int segmentLength = r - l + 1;

    for (int blockLen = 1; blockLen <= segmentLength; blockLen++) {
        if (segmentLength % blockLen != 0) continue;

        bool periodic = true;
        for (int i = l; i + blockLen <= r; i++) {
            if (A[i] != A[i + blockLen]) {
                periodic = false;
                break;
            }
        }

        if (!periodic) continue;

        for (int split = l; split <= l + blockLen; split++) {
            bool leftAllEqual = allEqual(l, split);
            bool leftPattern2 = checkPattern2(l, split);

            bool rightAllEqual = true;
            if (split + 1 <= l + blockLen - 1) {
                rightAllEqual = allEqual(split + 1, l + blockLen - 1);
            }

            bool rightPattern2 = true;
            if (split + 1 <= l + blockLen - 1) {
                rightPattern2 = checkPattern2(split + 1, l + blockLen - 1);
            }

            if (leftAllEqual && rightPattern2) return true;
            if (leftPattern2 && rightAllEqual) return true;
        }
    }

    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;

    A.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> A[i];

    bool answer = false;
    if (k == 1) {
        answer = allEqual(0, n - 1);
    } else if (k == 2) {
        answer = checkPattern2(0, n - 1);
    } else {
        answer = checkPattern3(0, n - 1);
    }

    if (answer) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {

    int tc;
    cin >> tc;

    while (tc--) solve();

    return 0;
}
