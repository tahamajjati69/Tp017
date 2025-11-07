#include <iostream>
using namespace std;

class Point3D {
private:
    double x, y, z;
public:
    Point3D() : x(0), y(0), z(0) {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
};

int main() {
    Point3D p1;
    Point3D p2(1.5, 2.5, 3.5);

    cout << "Point 1 : (" << p1.getX() << ", " << p1.getY() << ", " << p1.getZ() << ")\n";
    cout << "Point 2 : (" << p2.getX() << ", " << p2.getY() << ", " << p2.getZ() << ")\n";

    return 0;
}
