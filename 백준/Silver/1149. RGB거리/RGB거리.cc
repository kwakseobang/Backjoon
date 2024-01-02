#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int ensewr(vector<vector<int>>&v);
int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>>v(n,vector<int>(3,0));
    int insertNum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<3; j++){
            cin >> insertNum;
            v[i][j] = insertNum;
        }
    }
    cout << ensewr(v);
    
    
    return 0;
}
void patternFirst(vector<vector<int>>&dp , int cmpVal,int i, int j) {
    dp[i][j] = min(dp[i-1][j+1],dp[i-1][j+2]) + cmpVal;

}
void patternSecond(vector<vector<int>>&dp , int cmpVal,int i, int j) {
    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j+1]) + cmpVal;
}
void patternThird(vector<vector<int>>&dp , int cmpVal,int i, int j) {
    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j-2]) + cmpVal;
}


int ensewr(vector<vector<int>>&v) {
    int row = v.size();
    int col = v[0].size();
    vector<vector<int>>dp(row,vector<int>(col,0));
    //첫 줄은 그대로 초기화
    for(int i = 0; i <col; i++){
        dp[0][i] = v[0][i];
    }
    for(int i = 1; i < row; i++){
        for(int j = 0; j<col;j++){
            if( j == 0){
                patternFirst(dp, v[i][j], i, j);
            }
            else if (j == 1){
                patternSecond(dp, v[i][j], i, j);
            }
            else {
                patternThird(dp, v[i][j], i, j);
            }
        }
 
        
    }
    int res = min({dp[row-1][0],dp[row-1][1],dp[row-1][2]});
    return res;
}
