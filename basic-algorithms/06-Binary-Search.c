#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    // Test 1: Target present in array
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    printf("Test 1: %d | Expected: 4\n", search(nums1, 6, 9));

    // Test 2: Target not present in array
    int nums2[] = {-1, 0, 3, 5, 9, 12};
    printf("Test 2: %d | Expected: -1\n", search(nums2, 6, 2));

    // Test 3: Edge case with single matching element
    int nums3[] = {5};
    printf("Test 3: %d | Expected: 0\n", search(nums3, 1, 5));

    // Test 4: Edge case with single non-matching element
    int nums4[] = {5};
    printf("Test 4: %d | Expected: -1\n", search(nums4, 1, -5));

    return 0;
}
