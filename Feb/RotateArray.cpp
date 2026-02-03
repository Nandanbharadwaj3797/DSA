//https://leetcode.com/problems/rotate-array/description/
#include<bits/stdc++.h>
using namespace std;
// 1st approach: Manual reverse function
class Solution {
public:
 void reversepart(int i,int j,vector<int>&v){
        while(i<=j){
         int temp=v[i];
         v[i]=v[j];
            v[j]=temp;
            i++;
            j--; 
        }
    }
    void rotate(vector<int>& v, int k) {
    int j=v.size();
    if(k>j) k=k%j;
   reversepart(0,j-k-1,v);
   reversepart(j-k,j-1,v);
   reversepart(0,j-1,v);
    }
};

// 2nd approach: Using STL reverse function

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;

        reverse(nums.begin()+(n-k),nums.end());
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin(),nums.end());
        
    }
};