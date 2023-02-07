#include "bits/stdc++.h" 
using namespace std;   
/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int N = matrix.size();
        int start = matrix[0][0];
        int end = matrix[N - 1][N - 1]; 
        for(int i = start; i <= end; i++) { 
            q.push(i);
            if(q.size() > k)
                q.pop(); 
        }
        return q.top();
    }
};
// @lc code=end

/**
 * [1,  5, 9]
 * [10,11,13]
 * [12,13,15]  k = 8
 * 
 * 13
*/

