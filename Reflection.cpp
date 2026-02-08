#include <iostream>
#include <vector>
#include <string>

using namespace std;

int changeNumber(vector<vector<int>>& grid, int n, int u) {
    int changes = 0;
    int totalChanges = 0;
    int hashtags = 0;
    int dots = 0;
    // grid[i][n - j - 1] grid[n - i - 1][j] grid[n - i - 1][n - j - 1]) {
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            int changes = 0;
            int hashtags = 0;
            int dots = 0;
            if (grid[i][j]) {
                hashtags++;
            } else {
                dots++;
            }
            if (grid[i][n - j - 1]) {
                hashtags++;
            } else {
                dots++;
            }
            if (grid[n - i - 1][j]) {
                hashtags++;
            } else {
                dots++;
            }
            if (grid[n - i - 1][n - j - 1]) {
                hashtags++;
            } else {
                dots++;
            }
            
            if (hashtags == 4 || dots == 4) {
                changes += 0;
            }
            else if (hashtags > dots) {
                changes += dots;
            } 
            else if (dots > hashtags) {
                changes += hashtags;
            }
            else if (dots == hashtags) {
                changes += 2;
            }

            totalChanges += changes;
        }
    }

    return totalChanges;
    
}

int singleCellChanges(vector<vector<int>>& grid, int x, int y, int n) {
    int changes = 0;
    int hashtags = 0;
    int dots = 0;
    if (grid[x][y]) {
        hashtags++;
    } else {
        dots++;
    }
    if (grid[x][n - y - 1]) {
        hashtags++;
    } else {
        dots++;
    }
    if (grid[n - x - 1][y]) {
        hashtags++;
    } else {
        dots++;
    }
    if (grid[n - x - 1][n - y - 1]) {
        hashtags++;
    } else {
        dots++;
    }
    
    if (hashtags == 4 || dots == 4) {
        changes += 0;
    }
    else if (hashtags > dots) {
        changes += dots;
    } 
    else if (dots > hashtags) {
        changes += hashtags;
    }
    else if (dots == hashtags) {
        changes += 2;
    }

    return changes;
}

int main() {

    int n, u;
    cin >> n >> u;

    vector<vector<int>> grid(n, vector<int>(n, 0)); 

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '#') {
                grid[i][j] = 1;
            }
        }
    }

    int totalChanges = 0;
    totalChanges = changeNumber(grid, n, u);


    cout << totalChanges << endl;
    while (u--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int change1 = singleCellChanges(grid, x, y, n);
        if (grid[x][y] == 1) {
            grid[x][y] = 0;
        } else {
            grid[x][y] = 1;
        }

        int change2 = singleCellChanges(grid, x, y, n);
        
        if (change1 > change2) {
            totalChanges -= (change1 - change2);
        } else {
            totalChanges += (change2 - change1);
        }

        cout << totalChanges << endl;
    }

    return 0;
}