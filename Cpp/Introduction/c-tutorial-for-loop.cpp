// basic for loop

#include <iostream>

int main()
{

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);

    // loop through all numbers from a to b inclusive
    for (int n = a; n <= b; n++)
    {
        switch (n)
        {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        default:
            if (n % 2 == 0)
                printf("even");
            else
                printf("odd");
        }
        printf("\n");
    }

    return 0;
}
