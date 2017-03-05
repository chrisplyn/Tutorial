### 题意
* 中文描述  
    假如你是一个职业盗贼，打算去盗窃沿街的一个所有房屋。每个房屋都藏有一定数目的钱，如果相邻的房屋同一天晚上遭到盗窃，安保系统就会自动通知警察，这将导致你无法继续盗窃。  
    给定一列非负整数，代表每个房间的钱的额度，确定今晚你可以在不京东警察的情况下可以盗窃的最多的钱数。
* 题意分析  
    在一个给定的非负序列中，找出最大的序列和，找出的这个序列每两个数不能相邻。

### 题解 
* <b>算法及复杂度（Run Time 0ms）</b>
    * 这个一个求最优解的问题，自然而然想到动态规划。因为动态规划常用来求最优解。先假定这个问题可以用动态规划进行求解，找最优子结构，假定求前n+1(n >= 2 )个房屋盗贼能偷到的最多的钱为dp[n]。由于每个房屋的钱都是非负的，所以前n+1个房屋的总的可以偷的钱，要么与前n个房屋偷的钱相等，要么等于前n-1个房屋可以偷的钱，加上第n+1个房屋的钱数，除了这两种情况外，没有其他情况。即状态转移方程写为: `dp[n] = max(dp[n-1], dp[n-2] + num[n]), n>=2`，这里dp[n]表示前n+1个房屋可以偷的总的钱数，是一个状态量。
    * 时间复杂度: 由于每个状态只计算一次，并且状态是一维的，所有如果输入房屋数量为n，时间复杂度为O(n)。
    * 代码参见solution.cpp。

### 算法正确性
* 如算法及复杂度过程中所述，前n+1个房屋的总的可以偷的最多钱(dp[n])，要么与前n个房屋偷的钱相等(dp[n-1])，要么等于前n-1个房屋可以偷的钱(dp[n-2])，加上第n+1个房屋的钱数(nums[n])，除了这两种情况外，没有其他情况。这里用反证法证明不存在其他情况。反证法：如果存在除了上述两种情况外的情况，则加入存在`dp[n] = dp[n-3] + nums[n] > max(dp[n-1], dp[n-2] + num[n])`,从式可以看出: `dp[n-3] + nums[n] > dp[n-2] + nums[n]`。这与定义前n+1个房屋总的可以偷得最多的钱为dp[n]矛盾，所以不可能存在其他情况。因此状态转移方程正确。 
* 举个例子验证一下：
    
    ```
    // 给定数组
    nums = [1, 6, 3, 4, 5];
    // 求解dp,根据dp[n] = max(dp[n-1], dp[n-2] + num[n]), n>=2
    dp = [1, 6, 6, 10, 11];
    ```