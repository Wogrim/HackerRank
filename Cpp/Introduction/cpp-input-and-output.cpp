// simple input and output

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c);
    return 0;

    // or
    scanf("%d %d %d", &a, &b, &c);
    printf("%d", a + b + c);
}
