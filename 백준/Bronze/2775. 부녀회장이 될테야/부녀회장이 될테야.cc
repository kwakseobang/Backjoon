#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> dp(15,vector<int>(15,0));
    
    int num = 0;
    cin >> num;
    int k = 0,n =  0;
    for(int i = 1; i < 15; i++){
        dp[0][i] = i;
    }
    for(int i = 0; i <num;i++){
        cin >>k; cin >> n;
       
        for(int i = 1; i<=k;i++){
            for(int j = 1; j<=n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
     
          
        cout <<dp[k][n] << '\n';
    }
    return 0;
}
