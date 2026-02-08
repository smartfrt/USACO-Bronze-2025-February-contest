#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<int> counts(n+1);
    for (int value : numbers) {
        counts[value]++;
    }
    
    int operations = 0;
    for (int i = 0; i <= n; i++) {
        cout << max(operations, counts[i]) << endl;
        if (counts[i] == 0) {
            operations++;
        }
    }
    return 0;
}