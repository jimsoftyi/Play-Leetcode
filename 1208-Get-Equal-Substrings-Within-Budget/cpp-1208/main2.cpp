/// Source : https://leetcode.com/problems/get-equal-substrings-within-budget/
/// Author : liuyubobobo
/// Time   : 2019-09-30

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window without using int vector
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int l = 0, r = -1, cur = 0, res = 0; // Sliding Window : [l, r]
        while(l < s.size()){
            if(cur <= maxCost) res = max(res, r - l + 1);

            if(cur <= maxCost && r + 1 < s.size()) cur += abs(s[++ r] - t[r]);
            else cur -= abs(s[l] - t[l ++]);
        }
        return res;
    }
};


int main() {

    cout << Solution().equalSubstring("abcd", "bcdf", 3) << endl;
    // 3

    cout << Solution().equalSubstring("abcd", "cdef", 3) << endl;
    // 1

    cout << Solution().equalSubstring("abcd", "acde", 0) << endl;
    // 1

    return 0;
}