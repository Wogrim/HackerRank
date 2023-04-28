// deque is like a vector but efficient insert/delete at both ends

#include <iostream>
#include <deque>

using namespace std;

// debug helper function
void printD(deque<int> d)
{
    deque<int>::iterator p = d.begin();
    while (p != d.end())
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

void printKMax(int arr[], int n, int k)
{
    // d holds indices of the array of "local-maxes", in order of descending value
    // a "local-max" is when the number is bigger than elements to its right (within the current window)
    // because going through the whole window each time to find max is too slow as k gets larger
    deque<int> d;
    d.clear();
    d.push_back(0);
    int newval;
    // set up for intial window
    for (int i = 1; i < k; i++)
    {
        newval = arr[i];
        // the new value makes all values in the window <= to it irrelevant
        // so remove them from d
        if (!d.empty())
        {
            if (arr[d.front()] <= newval)
                d.clear();
            else
            {
                while (arr[d.back()] <= newval)
                    d.pop_back();
            }
        }
        // add the new index
        d.push_back(i);
    }
    // printD(d); // DEBUG
    // first window's max
    cout << arr[d.front()] << " ";

    // remaining windows
    for (int i = k; i < n; i++)
    {

        // remove front of the window if applicable
        // can only be at d.front() because larger later numbers would clear it
        if (d.front() <= i - k)
            d.pop_front();

        newval = arr[i];
        // the new value makes all values in the window  <= to it irrelevant
        // so remove them from d
        if (!d.empty())
        {
            if (arr[d.front()] <= newval)
                d.clear();
            else
            {
                while (arr[d.back()] <= newval)
                    d.pop_back();
            }
        }
        // add the new index
        d.push_back(i);

        // printD(d); // DEBUG
        // this window's max
        cout << arr[d.front()] << " ";
    }
    cout << "\n";
}

//////////////////////////////////////////////////

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            scanf("%d", arr + i);
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
