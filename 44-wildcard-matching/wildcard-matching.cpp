class Solution {
public:
    bool helper(int i, int j, string& s, string& p, int n, int m, vector<vector<int>>& dp){
        if(j>=m) return (i>=n ? true : false);
        if(i>=n){
            for(int k=j;k<m;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]!='*' && p[j]!='?'){
            if(p[j]==s[i])
            return dp[i][j] = helper(i+1, j+1, s, p, n, m, dp);
            return dp[i][j] = false;
        }
        else if(p[j]=='?'){
            return dp[i][j] = helper(i+1, j+1, s, p, n, m, dp);
        }
        else{
            bool ans = false;
            for(int k=i;k<=n;k++){
                ans|=helper(k, j+1, s, p, n, m, dp);
            }
            return dp[i][j] = ans;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, 0));
        int n=s.size();
        int m=p.size();
        dp[n][m] = 1;
        for(int j=m-1;j>=0;j--){
            if(p[j]=='*') dp[n][j]=1;
            else break;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(p[j]!='*' && p[j]!='?'){
                    if(p[j]==s[i])
                        dp[i][j] = dp[i+1][j+1];
                    else
                        dp[i][j] = 0;
                }
                else if(p[j]=='?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    for(int k=n; k>=i;k--)
                    dp[i][j]|= dp[k][j+1];
                }
            }
        }
        return dp[0][0];  
    }
};