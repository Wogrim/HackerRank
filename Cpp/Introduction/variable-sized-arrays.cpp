// a jagged 2D array (a bit of a pain without using vector<>)

#include <cstdio>

int main()
{
    // number of arrays and queries
    int n, q;
    scanf("%d %d", &n, &q);

    // create the array of arrays
    int **arrays = new int*[n];

    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        // create the inner array
        arrays[i] = new int[k];
        // read data into this inner array
        for (int j = 0; j < k; j++)
            scanf("%d", &arrays[i][j]);
    }

    // read queries and output
    int i, j;
    for (int a = 0; a < q; a++)
    {
        scanf("%d %d", &i, &j);
        printf("%d\n", arrays[i][j]);
    }

    // free the inner arrays
    for(int i = 0; i < n; i++)
        delete[] arrays[i];
    // free the array of arrays
    delete[] arrays;

    return 0;
}
