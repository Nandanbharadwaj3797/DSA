// https://leetcode.com/problems/trionic-array-ii/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();

        int peak1, valley, idx;
        long long bestExtra, tempSum, currentSum;
        long long maxAnswer = LLONG_MIN;

        for (int start = 0; start < n; start++) {
            idx = start + 1;
            currentSum = 0;

            // -------- first increasing segment --------
            for (; idx < n && nums[idx - 1] < nums[idx]; idx++);
            peak1 = idx - 1;

            if (peak1 == start) {
                continue;
            }

            // -------- decreasing segment --------
            currentSum += nums[peak1] + nums[peak1 - 1];

            for (; idx < n && nums[idx - 1] > nums[idx]; idx++) {
                currentSum += nums[idx];
            }

            valley = idx - 1;

            if (valley == peak1 || valley == n - 1 || nums[idx] <= nums[valley]) {
                start = valley;
                continue;
            }

            // -------- third increasing segment --------
            currentSum += nums[valley + 1];

            // maximize third segment
            bestExtra = 0;
            tempSum = 0;

            for (int k = valley + 2; k < n && nums[k] > nums[k - 1]; k++) {
                tempSum += nums[k];
                bestExtra = max(bestExtra, tempSum);
            }

            currentSum += bestExtra;

            // maximize first segment (backward)
            bestExtra = 0;
            tempSum = 0;

            for (int k = peak1 - 2; k >= start; k--) {
                tempSum += nums[k];
                bestExtra = max(bestExtra, tempSum);
            }

            currentSum += bestExtra;

            // update answer
            maxAnswer = max(maxAnswer, currentSum);

            start = valley - 1;
        }

        return maxAnswer;
    }
};
