#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int multi_move(int er, int ec, vector<vector<int>> &dp)
{
    dp[er][ec] = 1;
    for (int sr = er; sr >= 0; sr--)

    {
        for (int sc = ec; sc >= 0; sc--)

        {

            if (sr == er)
            {
                for (int jump = 1; sc + jump <= ec; jump++)
                {

                    dp[sr][sc] += dp[sr][sc + jump];
                }
            }

            else if (sc == ec)
            {
                for (int jump = 1; sr + jump <= er; jump++)
                {

                    dp[sr][sc] += dp[sr + jump][sc];
                }
            }

            else
            {
                for (int jump = 1; sc + jump <= ec; jump++)
                {

                    dp[sr][sc] += dp[sr][sc + jump];
                }
                for (int jump = 1; sr + jump <= er; jump++)
                {

                    dp[sr][sc] += dp[sr + jump][sc];
                }

                for (int jump = 1; jump + sc <= ec && jump + sr <= er; jump++)
                {
                    dp[sr][sc] += dp[sr + jump][sc + jump];
                }
            }
        }
    }

    return dp[0][0];
}

int min_cost1 = INT_MAX;
int min_cost(int sr, int sc, int er, int ec, vector<vector<int>> &cost, vector<vector<int>> &dp1)
{
    int minCost1;
    int minCost2;
    if (dp1[sr][sc] != -1)
    {
        return dp1[sr][sc];
    }

    if (sr == er && sc == ec)
    {
        dp1[sr][sc] = cost[er][ec];
        return cost[er][ec];
    }

    if (sr + 1 <= er)
    {
        minCost1 = min(min_cost1, min_cost(sr + 1, sc, er, ec, cost, dp1));
    }

    if (sc + 1 <= ec)
    {
        minCost2 = min(min_cost1, min_cost(sr, sc + 1, er, ec, cost, dp1));
    }

    int final_cost = min(minCost1, minCost2);

    dp1[sr][sc] = final_cost + cost[sr][sc];
    return final_cost + cost[sr][sc];
}

int min_cost2(int er, int ec, vector<vector<int>> &cost, vector<vector<int>> &dp1)
{
    int minCost1;
    int minCost2;
    dp1[er][ec] = cost[er][ec];
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp1[sr][sc] = cost[sr][sc];
                continue;
            }

            if (sr + 1 <= cost.size() - 1)
            {
                minCost1 = min( minCost1, dp1[sr + 1][sc]);
            }
            if (sc + 1 <= cost[0].size() - 1)
            {
                minCost2 = min( minCost2, dp1[sr][sc + 1]);
            }

            int final_cost = min(minCost1, minCost2);
            dp1[sr][sc] = final_cost + cost[sr][sc];
        }
    }
    return dp1[0][0];
}

vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};

int gold_mine1(int sr, int sc, int er, int ec, vector<vector<int>> &gold, vector<vector<int>> &dp1)
{
    int maxCost1 = INT_MIN;

    if ((sr + 1 > er || sc + 1 > ec) && (sr - 1 > er || sc + 1 > ec) && (sr + 0 > er || sc + 1 > ec))
    {
        dp1[sr][sc] = gold[sr][sc];
        return gold[sr][sc];
    }

    if (dp1[sr][sc] != -1)
    {
        return dp1[sr][sc];
    }

    for (int d = 0; d < dir.size(); d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if (r < gold.size() && c < gold[0].size())
        {
            maxCost1 = max(maxCost1, gold_mine1(r, c, er, ec, gold, dp1));
        }
    }
    dp1[sr][sc] = maxCost1 + gold[sr][sc];
    return maxCost1 + gold[sr][sc];
}

int goldmine2(int s, int er, int ec, vector<vector<int>> &gold, vector<vector<int>> &dp1)
{

    for (int sr = er; sr >= 0; sr--)
    {

        for (int sc = ec; sc >= 0; sc--)
        {
            int max1 = INT_MIN;
            int max3 = INT_MIN;
            int max2 = INT_MIN;

            if ((sr + 1 > er || sc + 1 > ec) && (sr - 1 > er || sc + 1 > ec) && (sr + 0 > er || sc + 1 > ec))
            {
                dp1[sr][sc] = gold[sr][sc];
                continue;
            }
            if (sr - 1 <= er && sc + 1 <= ec)
            {
                max1 = max(max1, dp1[sr - 1][sc + 1]);
            }
            if (sr + 0 <= er && sc + 1 <= ec)
            {
                max2 = max(max2, dp1[sr + 0][sc + 1]);
            }
            if (sr + 1 <= er && sc + 1 <= ec)
            {
                max3 = max(max3, dp1[sr + 1][sc + 1]);
            }

            int final_cost = max(max1, max(max2, max3));
            dp1[sr][sc] = final_cost + gold[sr][sc];
        }
    }
    return dp1[0][0];
}

int tile_problem(int n)
{
    vector<int> dp1(n + 1, 0);

    dp1[0] = 0;
    dp1[1] = 1;
    dp1[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }
    return dp1[n];
}
int rod_cutting(int n, vector<int> &price)
{

    vector<int> dp1(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val, price[j] + dp1[i - j - 1]);
        }
        dp1[i] = max_val;
    }
    return dp1[n];
}
int rod_cut_rec(int n, vector<int> &price, vector<int> &dp1)
{
    if (dp1[n] != 0)
    {
        return dp1[n];
    }
    if (n == 1)
    {
        return price[n - 1];
    }
    int max_val = INT_MIN;
    for (int i = 1; i <=n; i++)
    {

        max_val = max(max_val, price[i-1] + rod_cut_rec(n - i, price, dp1));

        dp1[n] = max_val;
    }

    return dp1[n];
}

int bionomial_coefficient(int n, int k)
{
    vector<vector<int>> dp1(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                dp1[i][j] = 1;
                //continue;
            }
            else
            {
                dp1[i][j] = (dp1[i - 1][j] + (j * dp1[i - 1][j - 1]));
            }
        }
    }
    return dp1[n][k];
}

int max_val = INT_MIN;

int min_path(vector<int> &arr, vector<int> &dp1)
{

    dp1[arr.size() - 1] = 0;

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        int min_val = 1e6;
        for (int j = 1; j <= arr[i] && j + i < arr.size(); j++)
        {

            min_val = min(min_val, dp1[i + j]);
        }
        dp1[i] = min_val + 1;
    }
    for (int i = 0; i < dp1.size(); i++)
    {
        cout << dp1[i] << " ";
    }
    cout << endl;
    return dp1[0];
}

int pair_ways_mem(int n, vector<int> dp1)
{
    if (n == 0 || n == 1)
    {
        dp1[n] = 1;
        return 1;
    }
    if (dp1[n] != -1)
    {
        return dp1[n];
    }

    int ans = pair_ways_mem(n - 1, dp1) + (n - 1) * pair_ways_mem(n - 2, dp1);
    dp1[n] = ans;
    return dp1[n];
}

int pair_ways(int n)
{
    vector<int> dp1(n + 1, 0);
    dp1[0] = 1;
    dp1[1] = 1;
    // dp1[2]=2;
    for (int i = 2; i <= n; i++)
    {
        dp1[i] = (dp1[i - 2] * (i - 1)) + dp1[i - 1];
    }
    return dp1[n];
}
int pair_group(int n, int k)
{
    vector<vector<int>> dp1(k + 1, vector<int>(n + 1, 0));
    dp1[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
        {

            dp1[i][j] = (i * dp1[i][j - 1]) + dp1[i - 1][j - 1];
        }
    }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //     {
    //         cout<<dp1[i][j]
    //     }
    // }
    return dp1[k][n];
}
int lsubseq(string str)
{
    vector<vector<int>> dp1(str.length(), vector<int>(str.length(), 0));
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp1[i][j] = 1;
            }
            else if (str[i] == str[j])
            {
                dp1[i][j] = dp1[i + 1][j - 1] + 2;
            }
            else
            {
                dp1[i][j] = max(dp1[i + 1][j], dp1[i][j - 1]);
            }
        }
    }

    return dp1[0][str.length() - 1];
}

int lp_subsequence(string str)
{
    vector<vector<int>> dp1(str.length() + 1, vector<int>(str.length() + 1, 0));
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp1[i][j] = 1;
            }
            if (str[i] == str[j])
            {
                dp1[i][j] = dp1[i + 1][j] + dp1[i][j - 1] + 1;
            }
            else
            {
                dp1[i][j] = dp1[i + 1][j] + dp1[i][j - 1] - dp1[i + 1][j - 1];
            }
        }
    }
    return dp1[0][str.length()];
}

int lc_substring(string str1, string str2)
{

    vector<vector<int>> dp1(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    int res = INT_MIN;
    for (int i = 0; i <= str1.length(); i++)
    {
        for (int j = 0; j <= str2.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp1[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp1[i][j] = dp1[i - 1][j - 1] + 1;
                res = max(res, dp1[i][j]);
            }
        }
    }
    return res;
}

int lcs(string s1, string s2)
{
    vector<vector<int>> dp1(s1.length() + 1, vector<int>(s2.length() + 1, 0));

    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp1[i][j] = 0;
                continue;
            }

            if (s1[i - 1] == s2[j - 1])
            {
                dp1[i][j] = dp1[i - 1][j - 1] + 1;
            }
            else
            {
                dp1[i][j] = max(dp1[i - 1][j], dp1[i][j + 1]);
            }
        }
    }
    return dp1[s1.length()][s2.length()];
}
int mcm_rec(int st, int end, vector<int> &row, vector<int> &col)
{
    if (st == end)
    {
        return 0;
    }
    int min_ = 1e6;
    for (int cut = st; cut < end; cut++)
    {
        int left = mcm_rec(st, cut, row, col);
        int right = mcm_rec(cut + 1, end, row, col);
        int cost = left + right + row[st] * col[cut] * col[end];

        min_ = min(min_, cost);
    }
    return min_;
}

int sat_sun(string s1, string s2, int i, int j, int count)
{
    if (i == s1.length())
    {
        return count;
    }

    int m = s1.length();
    int n = s2.length();
    //  if(m<n)
    //  {
    //      if(i==)
    //  }
    int a, b, c;
    if (s1[i] == s2[j])
    {
        sat_sun(s1, s2, i + 1, j + 1, count);
    }

    else
    {
        a = sat_sun(s1, s2, i + 1, j, count + 1);
        b = sat_sun(s1, s2, i, j + 1, count + 1);
        c = sat_sun(s1, s2, i + 1, j + 1, count + 1);
    }
    return min(a, min(b, c));
}
int max_subarray(vector<int> &arr)
{
    vector<vector<int>> dp1(arr.size() + 1, vector<int>(arr.size() + 1, 0));
    for (int gap = 0; gap < arr.size(); gap++)
    {
        for (int i = 0, j = gap; j < arr.size(); j++)
        {
            // if(gap==0)
            // {
            //     dp1[i][j]=arr[i]
            // }
        }
    }
}
int LIS(vector<int> &arr)
{
    vector<int> dp1(arr.size(), 0);
    dp1[0] = 1;
    int max_1 = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
        int max_local = INT_MIN;
        for (int j = i - 1; j >= 0; j--)
        {
            //  int max_local=INT_MIN;
            if (arr[i] > arr[j])
            {
                max_local = max(max_local, dp1[j]);
            }
        }
        if (max_local != INT_MIN)
        {
            dp1[i] = max_local + 1;
            max_1 = max(max_1, dp1[i]);
        }
        else
        {

            dp1[i] = 1;
            max_1 = max(max_1, dp1[i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << dp1[i] << " ";
    }
    return max_1;
}
int LDS(vector<int> &arr)
{
    vector<int> dp1(arr.size(), 0);
    dp1[0] = 1;
    int min_1 = INT_MIN;
    for (int i = 1; i < arr.size(); i++)
    {
        int min_local = INT_MIN;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] < arr[j])
            {
                min_local = max(min_local, dp1[j]);
            }
        }
        if (min_local != INT_MIN)
        {
            dp1[i] = min_local + 1;
            min_1 = max(dp1[i], min_1);
        }
        else
        {
            dp1[i] = 1;
            min_1 = max(dp1[i], min_1);
        }
    }
    //  for(int i=0;i<arr.size();i++)
    //  {
    //      cout<<dp1[i]<<" ";
    //  }
    return min_1;
}

int knap_01(vector<int> &profit, int W, int N, vector<int> &weights)
{
    vector<vector<int>> dp1(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp1[i][j] = max(dp1[i - 1][j], profit[i - 1] + dp1[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp1[i][j] = dp1[i - 1][j];
            }
        }
    }
    return dp1[N][W];
}

int edit_distance(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp1[i][j] = j;
                continue;
            }
            if (j == 0)
            {
                dp1[i][j] = i;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
            {
                dp1[i][j] = dp1[i - 1][j - 1];
            }
            else
            {
                dp1[i][j] = min(dp1[i - 1][j - 1], min(dp1[i][j - 1], dp1[i - 1][j])) + 1;
            }
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp1[n][m];
}

int main()
{

    // int m = 3;
    // int n = 3;
    // vector<vector<int>> dp(m, vector<int>(n, 0));
    // dp[m][n]=1;
    //   cout << multi_move(2, 2, dp);

    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<vector<int>>cost={ {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} };

    vector<vector<int>>dp1(cost.size(),vector<int>(cost[0].size(),-1));
    //cout<<min_cost(0,0,cost.size()-1,cost[0].size()-1,cost,dp1);
    cout<<min_cost2(cost.size()-1,cost[0].size()-1,cost,dp1)<<endl;
    // for(int i=0;i<cost.size();i++)
    // {
    //     for(int j=0;j<cost[0].size();j++)
    //     {
    //         cout<<dp1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // int maxq = -10000;
    // vector<vector<int>>gold={ {1, 3, 1, 5},
    //                {2, 2, 4, 1},
    //                {5, 0, 2, 3},
    //                {0, 6, 1, 2}};

    // vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    // // cout<<rod_cutting(8,price);
    // vector<int> dp1(price.size() + 1, 0);

    // cout << rod_cut_rec(8, price, dp1);

    // int maxs;
    // vector<vector<int>>dp1(gold.size(),vector<int>(gold[0].size(),-1));
    //  for(int i=0;i<gold.size();i++)
    //  {
    //    //  maxq=max(maxq,gold_mine1(i,0,gold.size()-1,gold[0].size()-1,gold,dp1));
    //    maxq=max(maxq,goldmine2(i,gold.size()-1,gold[0].size()-1,gold,dp1));

    //  }
    //  cout<<maxq<<endl;
    //  for(int i=0;i<gold.size();i++)
    // {
    //     for(int j=0;j<gold[0].size();j++)
    //     {
    //         cout<<dp1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //cout<<tile_problem(4);
    //cout<<bionomial_coefficient(4,2);

    // vector<int>arr={1,3,0,4,0,0,2,1,1,1};
    // vector<int>dp1(arr.size(),0);
    // cout<<min_path(arr,dp1);
    // vector<int>dp1(21,-1);
    // cout<<pair_ways(20);
    // cout<<pair_ways_mem(20,dp1);
    //cout<<pair_group(5,2);
    // cout<<lc_substring("abcdf","abc");
    //cout<<lcs("abbc","abc");
    // cout<<edit_distance("saturday","sunday",8,6);
    // vector<int>arr={50, 3, 10, 7, 40, 80};
    // cout<<LIS(arr);
    // cout<<LDS(arr);
    // vector<int>profit={60, 100, 120};
    // vector<int>weight={10, 20, 30};
    // cout<<knap_01(profit,50,3,weight);
    // vector<int>row={40,20,30,10};
    // vector<int>col={20,30,10,30};
    // cout<<mcm_rec(0,row.size()-1,row,col);
}
