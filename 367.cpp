class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        if (num == 0) return true;
        long long left = 0, right = num / 2;
        long long mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid > num) right = mid - 1;
            else if (mid * mid < num) left = mid + 1;
            else return true;
        }
        return false;
    }
};