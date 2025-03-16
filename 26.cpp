class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slowIndex = 0;
        int count = 0;

        for (int fastIndex = 1; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != nums[slowIndex]) {
                nums[++slowIndex] = nums[fastIndex];
                count++;
            }
        }
        return count + 1;

    }
};