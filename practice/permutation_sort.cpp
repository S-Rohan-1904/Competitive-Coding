#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int drops = 0, jumps = 0;
        int zero_idx = -1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) zero_idx = i;
            
            int next_i = (i + 1) % n;
            
            if (nums[i] > nums[next_i]) {
                drops++;
            }
            if (nums[i] < nums[next_i]) {
                jumps++;
            }
        }
        
        int ans = INT_MAX;
        // the array is normal sorted
        if(drops == 1) {
            // we either do left rotations or right rotations(rev + left + rev)
            ans = min({ans, zero_idx, 1 + n - zero_idx + 1});
        // the array is reverse sorted
        }else if(jumps == 1) {
            // we either do left + rev or rev + left
            ans = min({ans, zero_idx + 1 + 1, n - zero_idx - 1 + 1});
        // the array is not sorted at all
        } else {
            return -1;
        }
        
        return ans;
    }
};
