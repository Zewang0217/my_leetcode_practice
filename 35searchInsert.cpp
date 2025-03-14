int searchInsert(int* nums, int numsSize, int target) {
    int left, right, middle;
    left = 0;
    right = numsSize - 1;

    while (left <= right) {
        middle = left + (right - left) / 2;
        if (nums[middle] > target) { // left
            right = middle - 1;
        }
        else if (nums[middle] < target) { //right
            left = middle + 1;
        }
        else {
            return middle;
        }
    }
    return left;
}