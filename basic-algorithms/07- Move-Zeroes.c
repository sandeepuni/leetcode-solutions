#include <stdio.h>

void moveZeroes(int *nums, int numsSize)
{
    int pos = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            if (i != pos)
            {
                int temp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = temp;
            }
            pos++;
        }
    }
}

int main(void)
{
    // Test 1: Mixed zeros and non-zero elements
    int nums1[] = {0, 1, 0, 3, 12};
    moveZeroes(nums1, 5);
    printf("Test 1: [%d, %d, %d, %d, %d] | Expected: [1, 3, 12, 0, 0]\n",
           nums1[0], nums1[1], nums1[2], nums1[3], nums1[4]);

    // Test 2: Single zero
    int nums2[] = {0};
    moveZeroes(nums2, 1);
    printf("Test 2: [%d] | Expected: [0]\n", nums2[0]);

    // Test 3: No zeros present
    int nums3[] = {4, 2, 1};
    moveZeroes(nums3, 3);
    printf("Test 3: [%d, %d, %d] | Expected: [4, 2, 1]\n", nums3[0], nums3[1], nums3[2]);

    // Test 4: All zeros
    int nums4[] = {0, 0, 0};
    moveZeroes(nums4, 3);
    printf("Test 4: [%d, %d, %d] | Expected: [0, 0, 0]\n", nums4[0], nums4[1], nums4[2]);

    return 0;
}
