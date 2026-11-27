#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    free(result);
    return NULL;
}

int main(void) {
    // Test case 1: Typical case
    int nums1[] = {2, 7, 11, 15};
    int size1 = 0;
    int* res1 = twoSum(nums1, 4, 9, &size1);
    if (res1 != NULL && size1 == 2) {
        printf("Test 1 -> [%d, %d] (Expected: [0, 1])\n", res1[0], res1[1]);
        free(res1);
    }

    // Test case 2: Edge case with duplicate values
    int nums2[] = {3, 3};
    int size2 = 0;
    int* res2 = twoSum(nums2, 2, 6, &size2);
    if (res2 != NULL && size2 == 2) {
        printf("Test 2 -> [%d, %d] (Expected: [0, 1])\n", res2[0], res2[1]);
        free(res2);
    }

    // Test case 3: Edge case with negative numbers
    int nums3[] = {-3, 4, 3, 90};
    int size3 = 0;
    int* res3 = twoSum(nums3, 4, 0, &size3);
    if (res3 != NULL && size3 == 2) {
        printf("Test 3 -> [%d, %d] (Expected: [0, 2])\n", res3[0], res3[1]);
        free(res3);
    }

    return 0;
}
