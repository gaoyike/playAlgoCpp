#include "bits/stdc++.h" 
using namespace std;   

/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int N = s.size();
        vector<int> last(26);
        for(int i = 0; i < N; i++) {
            last[s[i]- 'a'] = i;
        }
        vector<int> seen(26); 
        stack<int> st;
        for(int i = 0; i < N; i++) {
            if(seen[s[i] - 'a'])
                continue;
            seen[s[i] - 'a']++;
            while (!st.empty() && s[st.top()] > s[i] && i < last[s[st.top()] - 'a'])
            {
                seen[s[st.top()] - 'a']--;
                st.pop();
            }
            st.push(i);
        }
        string res = "";
        while (!st.empty())
        {
            res = s[st.top()] + res;
            st.pop();
        }
        
        return res;
    } 
};
// @lc code=end

/**
 * [bcabc]
 * [01234]
 * res[0,1,2]   i = 3 ('b')
 * 
*/