#include <iostream>
#include <cmath>
using namespace std;

class Vec3 {
public:
    float x, y, z;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    Vec3 operator*(float k) const {
        return Vec3(x * k, y * k, z * k);
    }
    Vec3 operator/(float k) const {
        return Vec3(x / k, y / k, z / k);
    }
    Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }
    float operator[](int i) const {
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
        else cout << "Index out of range"<< "\n";
    }
    void unit() {
        float mag = length();
        if (mag != 0) {
            x /= mag;
            y /= mag;
            z /= mag;
        }
    }
    float length() const {
        return sqrt(x * x + y * y + z * z);
    }
    float dot(const Vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    Vec3 cross(const Vec3& v) const {
        return Vec3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }
    Vec3 reflect(const Vec3& normal) const {
        float dotProduct = this->dot(normal);
        return (*this) - normal * (2 * dotProduct);
    }
    Vec3 refract(const Vec3& normal, float refractive_index) const {
        float costheta = -this->dot(normal);
        float k = 1 - (1 - costheta * costheta)/(refractive_index * refractive_index);
        return ((*this) * refractive_index + normal * ( costheta*refractive_index - sqrt(k)));
    }
};

int main(){
    int x, y, z;
    cout << "Enter the x, y, z coordinates of the vector: ";
    cin >> x >> y >> z;
    Vec3 v(x, y, z);
    int x1,y1,z1;
    cout << "Enter the x, y, z coordinates of the second vector: ";
    cin >> x1 >> y1 >> z1;
    Vec3 v1(x1, y1, z1);  
    int nx, ny, nz;
    cout << "Enter the x, y, z coordinates of the normal vector: ";
    cin >> nx >> ny >> nz;
    Vec3 normal(nx, ny, nz);  
    Vec3 sum = v + v1;
    Vec3 diff = v - v1;
    Vec3 scaled = v * 2.0f;
    Vec3 normalized = v;
    normalized.unit();
    float dotProduct = v.dot(v1);
    Vec3 crossProduct = v.cross(v1);
    Vec3 reflected = v.reflect(normal);
    float refractive_index ;
    cout << "Enter the refractive index: ";
    cin >> refractive_index;
    Vec3 refracted = v.refract(normal, refractive_index);
    cout << "Sum: (" << sum.x << ", " << sum.y << ", " << sum.z << ")\n";
    cout << "Difference: (" << diff.x << ", " << diff.y << ", " << diff.z << ")\n";
    cout << v.length() << "\n";
    cout << "Scaled: (" << scaled.x << ", " << scaled.y << ", " << scaled.z << ")\n";
    cout << "Normalized: (" << normalized.x << ", " << normalized.y << ", " << normalized.z << ")\n";
    cout << "Dot Product: " << dotProduct << "\n";
    cout << "Cross Product: (" << crossProduct.x << ", " << crossProduct.y << ", " << crossProduct.z << ")\n";
    cout << "Reflected: (" << reflected.x << ", " << reflected.y << ", " << reflected.z << ")\n";
    cout << "Refracted: (" << refracted.x << ", " << refracted.y << ", " << refracted.z << ")\n";
    return 0;
}
