// primitive array of uknown size

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    // unknown-length array must be dynamically allocated, is an int*
    int *nums = new int[n];

    // read numbers into the array
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    // print numbers from the array back to front
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", nums[i]);

    // free the memory used by the dynamically-allocated array
    delete[] nums;

    return 0;
}
