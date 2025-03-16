class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int pos = n - 1;
        vector<int> res(n);

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            if (leftSquare < rightSquare) {
                res[pos] = rightSquare;
                right--;
            }
            else {
                res[pos] = leftSquare;
                left++;
            }
            pos--;
        }
        return res;
    }
};

//快慢指针， 8ms

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);  // 直接分配空间，避免 push_back 额外开销
    int left = 0, right = n - 1;
    int pos = n;  // 先设为 n，后面用 `--pos` 直接递减

    while (left <= right) {
        int leftVal = nums[left];
        int rightVal = nums[right];

        if (abs(leftVal) > abs(rightVal)) {
            result[--pos] = leftVal * leftVal; // 先自减 pos 再赋值
            left++;
        }
        else {
            result[--pos] = rightVal * rightVal;
            right--;
        }
    }

    return result;
}
 //优化后，变成0ms