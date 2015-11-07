#include <iostream>
using namespace std;

class Box
{
public:
    
    double getVolume(void)
    {
        return length * breadth * height;
    }
    void setLength( double len )
    {
        length = len;
    }
    
    void setBreadth( double bre )
    {
        breadth = bre;
    }
    
    void setHeight( double hei )
    {
        height = hei;
    }
    // Overload + operator to add two Box objects.
    Box operator+(const Box& b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }
    
    Box operator-(const Box& b)
    {
        Box box;
        box.length = this->length - b.length;
        box.breadth = this->breadth - b.breadth;
        box.height = this->height - b.height;
        return box;
    }
    
private:
    int length;      // Length of a box
    int breadth;     // Breadth of a box
    int height;      // Height of a box
};
// Main function for the program
int main( )
{
    Box Box1;                // Declare Box1 of type Box
    Box Box2;                // Declare Box2 of type Box
    Box Box3;                // Declare Box3 of type Box
    int volume = 0;     // Store the volume of a box here
    
    // box 1 specification
    Box1.setLength(6);
    Box1.setBreadth(7);
    Box1.setHeight(5);
    
    // box 2 specification
    Box2.setLength(12);
    Box2.setBreadth(13);
    Box2.setHeight(10);
    
    // volume of box 1
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;
    
    // volume of box 2
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume <<endl;
    
    // Add two object as follows:
    Box3 = Box1 + Box2;
    
    // volume of box 3
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;

    // Subtract two object as follows:
    Box3 = Box1 - Box2;
    
    // volume of box 3
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;
    
    
    return 0;
}