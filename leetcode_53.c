/*
Solution to Leetcode problem 53

Maximum Subarray
Return maximum sum of contiguous subarray

Approach:
Kadane's algorithm
*/

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int max_so_far = -1000000;
    int max_ending_here = 0;
    for(int i = 0; i < numsSize; i++) {
        max_ending_here = max_ending_here + nums[i];
        if(max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
        if(max_ending_here < 0) {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = maxSubArray(nums, numsSize);
    printf("result is %d\n", result);
    return 0;
}