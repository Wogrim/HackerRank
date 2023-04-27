// group related variables in a struct for organization

#include <iostream>

using namespace std;

struct Student
{
    //by default everything in a struct is public
    int age;
    string first_name;
    string last_name;
    int standard;
};


//////////////////////////////////////////////////

int main()
{
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}
