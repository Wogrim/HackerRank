// algorithm problem made more annoying by locked code

#include <bits/stdc++.h>

using namespace std;

//////////////////////////////////////////
// MY CODE START

struct Workshop
{
    int start_time, end_time;

    // function just so we can conveniently set the times
    void setTime(int start, int dur)
    {
        start_time = start;
        end_time = start + dur;
    }
};

// function for sorting
bool end_time_comp(const Workshop &a, const Workshop &b)
{
    return a.end_time < b.end_time;
}

struct Available_Workshops
{
    // number of workshops
    int n;
    // array of workshops created in constructor
    Workshop *shops = nullptr;

    // constructor
    Available_Workshops(int n) : n(n)
    {
        if (n > 0)
            shops = new Workshop[n];
    }

    // deconstructor
    ~Available_Workshops()
    {
        // done with the workshop array
        if (n > 0)
            delete[] shops;
    }
};

Available_Workshops *initialize(int start[], int dur[], int n)
{
    Available_Workshops *ptr = new Available_Workshops(n);

    Workshop *shops = ptr->shops;

    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            shops[i].setTime(start[i], dur[i]);
        }
        // sort by end time
        sort(&shops[0], &shops[n], end_time_comp);
    }
    // no longer need start and dur arrays (and they're not deleted in main())
    delete[] start;
    delete[] dur;

    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{

    int total, time;
    int n = ptr->n;
    Workshop *shops = ptr->shops;

    // early exit if there are zero or one workshops
    if (n < 2)
    {
        delete ptr;
        return n;
    }

    // maximize the number of workshops you attend by always attending the one that
    // has the earliest end time, because that gives maximum opportunity to attend another
    time = shops[0].end_time;
    total = 1;
    for (int i = 1; i < n; i++)
    {
        // if the start time is after the current shop's end time, we do it
        if (shops[i].start_time >= time)
        {
            total++;
            time = shops[i].end_time;
        }
    }

    // no longer need ptr and it's not deleted in main()
    delete ptr;

    return total;
}

// MY CODE END
//////////////////////////////////////////

int main(int argc, char *argv[])
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
