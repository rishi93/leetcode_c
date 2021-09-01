/*
Solution to Leetcode problem 26.
Remove Duplicates from Sorted Array

Approach:
Straight forward approach
*/

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 1) {
        return numsSize;
    }
    
    int curr = 0;

    for(int i = 1; i < numsSize; i++) {
        if(nums[i] != nums[curr]) {
            curr += 1;
            nums[curr] = nums[i];
        }
    }

    return curr + 1;
}