// awful example, but notice overridden method Rectangle::display() is called

#include <iostream>

using namespace std;

////////////////////////////////////////
// MY CODE START

class Rectangle
{
protected:
    int width, height;

public:
    void read_input()
    {
        cin >> width >> height;
    }

    // display width and height
    void display() { cout << width << ' ' << height << endl; }
};

class RectangleArea : public Rectangle
{
public:
    // override Rectangle::display to display area
    void display() { cout << width * height << endl; }
};

// MY CODE END
////////////////////////////////////////

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}