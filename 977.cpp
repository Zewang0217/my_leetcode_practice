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

//����ָ�룬 8ms

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);  // ֱ�ӷ���ռ䣬���� push_back ���⿪��
    int left = 0, right = n - 1;
    int pos = n;  // ����Ϊ n�������� `--pos` ֱ�ӵݼ�

    while (left <= right) {
        int leftVal = nums[left];
        int rightVal = nums[right];

        if (abs(leftVal) > abs(rightVal)) {
            result[--pos] = leftVal * leftVal; // ���Լ� pos �ٸ�ֵ
            left++;
        }
        else {
            result[--pos] = rightVal * rightVal;
            right--;
        }
    }

    return result;
}
 //�Ż��󣬱��0ms