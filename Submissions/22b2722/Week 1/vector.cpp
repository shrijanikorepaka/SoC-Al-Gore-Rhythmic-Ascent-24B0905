#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Vec3 {
private:
    float x, y, z;

public:
    Vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3 operator+(const Vec3& other) {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(const Vec3& other) {
        return Vec3(x * other.x, y * other.y, z * other.z);
    }

    Vec3 operator/(const Vec3& other) {
        return Vec3(x / other.x, y / other.y, z / other.z);
    }

    Vec3 operator-() {
        return Vec3(-x, -y, -z);
    }

    float operator[](int index) {
        if (index == 0) return x;
        if (index == 1) return y;
        if (index == 2) return z;
        return 0;
    }

    Vec3 unit() {
        float len = length();
        return Vec3(x / len, y / len, z / len);
    }

    float length() {
        return sqrt(x * x + y * y + z * z);
    }

    float dot(const Vec3& other) {
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 cross(const Vec3& other) {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float getX() { return x; }
    float getY() { return y; }
    float getZ() { return z; }
};

bool isEqual(float a, float b, float tolerance = 0.001) {
    return abs(a - b) < tolerance;
}

void testConstructor() {
    Vec3 v(1.0, 2.0, 3.0);
    assert(isEqual(v[0], 1.0));
    assert(isEqual(v[1], 2.0));
    assert(isEqual(v[2], 3.0));
}

void testOperators() {
    Vec3 v1(1.0, 2.0, 3.0);
    Vec3 v2(4.0, 5.0, 6.0);
    
    Vec3 add = v1 + v2;
    assert(isEqual(add[0], 5.0));
    assert(isEqual(add[1], 7.0));
    assert(isEqual(add[2], 9.0));
    
    Vec3 sub = v1 - v2;
    assert(isEqual(sub[0], -3.0));
    assert(isEqual(sub[1], -3.0));
    assert(isEqual(sub[2], -3.0));
    
    Vec3 mul = v1 * v2;
    assert(isEqual(mul[0], 4.0));
    assert(isEqual(mul[1], 10.0));
    assert(isEqual(mul[2], 18.0));
    
    Vec3 div = v2 / v1;
    assert(isEqual(div[0], 4.0));
    assert(isEqual(div[1], 2.5));
    assert(isEqual(div[2], 2.0));
    
    Vec3 neg = -v1;
    assert(isEqual(neg[0], -1.0));
    assert(isEqual(neg[1], -2.0));
    assert(isEqual(neg[2], -3.0));
    }

int main() {
    testConstructor();
    testOperators();
    
    cout<< "All Vec3 tests passed successfully!";
    return 0;
}