#include <bits/stdc++.h>
using namespace std;

// 1 st approach: Simple mathematical approach with overflow checks
class Solution {
public:
    int reverse(int x) {
        int num = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // overflow check
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7))
                return 0;
            if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < -8))
                return 0;

            num = num * 10 + digit;
        }

        return num;
    }
};


// 2nd approach  

class Solution {
public:
    int reverse(int x) {
        long r = 0;
        while(x) {
            r = r*10+x%10;
            x = x/10;
        }
           
        if(r > INT_MAX || r < INT_MIN) return 0;
        return int(r);   
    }
};

// 3rd approach: Using stringstream
class Solution {
public:
    int reverse(int x) {
        stringstream ss;
        ss << x;
        string s = ss.str();
        bool negative = false;
        if(s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }
        std::reverse(s.begin(), s.end());
        long r;
        ss.clear();
        ss.str("");
        ss << s;
        ss >> r;
        if(negative) r = -r;
        if(r > INT_MAX || r < INT_MIN) return 0;
        return int(r);
    }
};