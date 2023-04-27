// passing pointers to a function lets you change originals

#include <stdio.h>

void update(int *a, int *b)
{
    //calculate new values
    int sum = *a + *b;
    int diff = *a - *b;
    if (diff < 0)
        diff = -diff;
    //change originals
    *a = sum;
    *b = diff;
}

int main()
{
    int a, b;
    // pointers are addresses
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    // pass the pointers to the function
    update(pa, pb);
    // a and b have changed
    printf("%d\n%d", a, b);

    return 0;
}
