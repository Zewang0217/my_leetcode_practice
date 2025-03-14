class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);

        int start = findStart(nums, target);
        int end = findEnd(nums, target);

        if (start == -1 && end != -1) start = end;

        res[0] = start;
        res[1] = end;

        return res;
    }

private:
    int findStart(const vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        int start = -1;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                if (nums[mid] == target) {
                    start = mid;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return start;
    }

    int findEnd(const vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        int end = -1;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                if (nums[mid] == target) {
                    end = mid;
                }
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return end;
    }
};