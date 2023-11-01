#include <iostream>
using namespace std;

void print(int r, int c) {
    int arr[r][c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    int z = 0;
    int o = 0;

    while (cnt < r * c) {
        for (int j = z; j < c - z; j++) {
            cout << arr[z][j] << " ";
            cnt++;
        }

        for (int i = z + 1; i < r - z; i++) {
            cout << arr[i][c - o - 1] << " ";
            cnt++;
        }

        if (cnt >= r * c) break;

        for (int j = c - o - 2; j >= z; j--) {
            cout << arr[r - z - 1][j] << " ";
            cnt++;
        }

        for (int i = r - o - 2; i > z; i--) {
            cout << arr[i][z] << " ";
            cnt++;
        }

        z++;
        o++;
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    print(r, c);
    return 0;
}


