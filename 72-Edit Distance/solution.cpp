int minDistance(string word1, string word2)
{
    int len1=word1.size(),len2=word2.size();
    int dp[len1+1][len2+1];
    dp[0][0]=0;//初始化边界
    for(int i=1;i<=len1;i++)//初始化边界
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=len2;i++)//初始化边界
    {
        dp[0][i]=i;
    }
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];//两个字符相等
            else dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));//两个字符不相等
        }
    }
    return dp[len1][len2];
}
