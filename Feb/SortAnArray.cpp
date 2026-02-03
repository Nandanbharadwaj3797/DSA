// https://leetcode.com/problems/sort-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Heapify a subtree rooted at index i
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // check left child
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        // check right child
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        // if root is not largest, swap and continue heapifying
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);   // move max to end
            heapify(nums, i, 0);      // restore heap
        }

        return nums;
    }
};
// Time Complexity: O(n log n)
// Space Complexity: O(1)


// 2nd approach: Using STL sort function
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums;
    }
};