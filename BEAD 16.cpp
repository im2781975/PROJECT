#include<bits/stdc++.h>
using namespace std;
const int ax = 1e3;
int n, m, addx = 0, addo = 0;
string dp[ax][ax];
void print(int n, int m){
    for(int i = 0; i <= n; i++){
        cout << i << " ";
        for(int j = 1; j <= m; j++){
            if(i == 0) {
                cout << j << "  ";
                continue;
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
void forward(char ch, int x, int y){
    for(int i = x; i <= n; i++){
        for(int j = y; j <= m; j++){
            if(i == x && j == y && dp[i][j] == "o " && dp[i - 1][j] != "x "){
                dp[i - 1][j] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "o " && dp[i - 1][j] == "x ") {
                if(dp[i - 2][j] == "- ") {
                    dp[i - 2][j] = dp[i][j];
                    dp[i - 1][j] = "- ";
                    dp[i][j] = "- ";
                    addx += 1;
                }
                else    continue;
            }
            if(i == x && j == y && dp[i][j] == "x " && dp[i + 1][j] != "o "){
                dp[i + 1][j] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "x " && dp[i + 1][j] == "o ") {
                if(dp[i + 2][j] == "- ") {
                    dp[i + 2][j] = dp[i][j];
                    dp[i + 1][j] = "- ";
                    dp[i][j] = "- ";
                    addo += 1;
                }
                else    continue;
            }
        }
    }
}
void backward(char ch, int x, int y){
    for(int i = x; i <= n; i++){
        for(int j = y; j <= m; j++){
            if(i == x && j == y && dp[i][j] == "o " && dp[i + 1][j] == "- "){
                dp[i + 1][j] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "o " && dp[i + 1][j] == "x ") {
                if(dp[i + 2][j] == "- ") {
                    dp[i + 2][j] = dp[i][j];
                    dp[i + 1][j] = "- ";
                    dp[i][j] = "- ";
                    addx += 1;
                }
                else    continue;
            }
            if(i == x && j == y && dp[i][j] == "x " && dp[i - 1][j] == "- "){
                dp[i - 1][j] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "x " && dp[i - 1][j] == "o ") {
                if(dp[i - 2][j] == "- ") {
                    dp[i - 2][j] = dp[i][j];
                    dp[i - 1][j] = "- ";
                    dp[i][j] = "- ";
                    addo += 1;
                }
                else    continue;
            }
        }
    }
}
void left(char ch, int x, int y){
    for(int i = x; i <= n; i++){
        for(int j = y; j <= m; j++){
            if(i == x && j == y && dp[i][j] == "o " && dp[i][j - 1] == "- "){
                dp[i][j - 1] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "o " && dp[i][j - 1] == "x ") {
                if(dp[i][j - 2] == "- "){
                    dp[i][j - 2] = dp[i][j];
                    dp[i][j - 1] = "- ";
                    dp[i][j] = "- ";
                    addo += 1;
                }
                else    continue;
            }
            if(i == x && j == y && dp[i][j] == "x " && dp[i][j - 1] == "- "){
                dp[i][j - 1] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "x " && dp[i][j - 1] == "o ") {
                if(dp[i][j - 2] == "- "){
                    dp[i][j - 2] = dp[i][j];
                    dp[i][j - 1] = "- ";
                    dp[i][j] = "- ";
                    addx += 1;
                }
                else    continue;
            }
        }
    }
}
void right(char ch, int x, int y){
    for(int i = x; i <= n; i++){
        for(int j = y; j <= m; j++){
            if(i == x && j == y && dp[i][j] == "o " && dp[i][j + 1] == "- "){
                dp[i][j + 1] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "o " && dp[i][j + 1] == "x ") {
                if(dp[i][j + 2] == "- "){
                    dp[i][j + 2] = dp[i][j];
                    dp[i][j + 1] = "- ";
                    dp[i][j] = "- ";
                }
                else    continue;
            }
            if(i == x && j == y && dp[i][j] == "x " && dp[i][j + 1] == "- "){
                dp[i][j + 1] = dp[i][j];
                dp[i][j] = "- ";
            }
            else if(i == x && j == y && dp[i][j] == "x " && dp[i][j + 1] == "o ") {
                if(dp[i][j + 2] == "- "){
                    dp[i][j + 2] = dp[i][j];
                    dp[i][j + 1] = "- ";
                    dp[i][j] = "- ";
                }
                else    continue;
            }
        }
    }
}
int main(){
    n = 8; m = 8;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 || i == 2)
                dp[i][j] = "x ";
            else if(i == n - 1 || i == n)
                dp[i][j] = "o ";
            else    dp[i][j] = "- ";
        }
    }
    print(n, m);
    while(addx != 8 || addo != 8){
        int x, y; char ch;
        cin >> ch >> x >> y;
        if(ch == 'U')    forward(ch, x, y);
        
        else if(ch == 'D')    backward(ch, x, y);
        else if(ch == 'L')    left(ch, x, y);
        else if(ch == 'R')    right(ch, x, y);
        else    continue;
        print(n, m);
    }
}
