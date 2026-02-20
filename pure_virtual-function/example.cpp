#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;  
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    // Shape s; // ❌ Error: abstract class cannot be instantiated
    Circle c;
    c.draw(); // ✅ Works fine
    return 0;
}