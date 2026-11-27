#include <stdio.h>

int maxProfit(int *prices, int pricesSize)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else if (prices[i] - minPrice > maxProfit)
        {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

int main(void)
{
    // Test 1: Typical profitable case
    int prices1[] = {7, 1, 5, 3, 6, 4};
    printf("Test 1: %d | Expected: 5\n", maxProfit(prices1, 6));

    // Test 2: Decreasing prices (no profit possible)
    int prices2[] = {7, 6, 4, 3, 1};
    printf("Test 2: %d | Expected: 0\n", maxProfit(prices2, 5));

    // Test 3: Edge case with single element
    int prices3[] = {5};
    printf("Test 3: %d | Expected: 0\n", maxProfit(prices3, 1));

    // Test 4: Edge case with all identical prices
    int prices4[] = {3, 3, 3, 3};
    printf("Test 4: %d | Expected: 0\n", maxProfit(prices4, 4));

    return 0;
}
