#include<cmath>
#include <stdexcept>

class Vec3 {
public:
    float x, y, z;

    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    
    //Operators
    Vec3 operator+(const Vec3& other) const {
      return Vec3(x + other.x, y + other.y, z + other.z);
    }
    Vec3 operator-(const Vec3& other) const {
      return Vec3(x - other.x, y - other.y, z - other.z);
    }
    Vec3 operator*(float scalar) const {
      return Vec3(x*scalar, y*scalar, z*scalar);
    }
    Vec3 operator/(float scalar) const {
      return Vec3(x/scalar, y/scalar, z/scalar);
    }
    Vec3 operator-() const {
      return Vec3(-x, -y, -z);
    }
    const float& operator[](int index) const {
      if (index == 0) return x;
      if (index == 1) return y;
      if (index == 2) return z;
    }

    //Methods
    float length() const {
      return std::sqrt(x*x + y*y + z*z);
    }
    Vec3 unit() const {
      float len = length();
      return *this / len;
    }
    float dot(const Vec3& other) const {
      return x * other.x + y * other.y + z * other.z;
    }
    Vec3 cross(const Vec3& other) const {
      return Vec3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
      );
    }
    Vec3 reflect(const Vec3& normal) const {
      return *this - (normal * (2.0f *this -> dot(normal)));
    }
    //helper for refract
    float length_squared() const {
      return x*x + y*y + z*z;
    }
    Vec3 refract(const Vec3& normal, float refractive_index) const {
      float cos_theta = std::fmin(-(*this).dot(normal), 1.0f);
      Vec3 perpendicular = (*this + (normal*cos_theta)) * refractive_index;
      Vec3 parallel = normal * -std::sqrt(std::fabs(1.0f - perpendicular.length_squared()));
      return parallel + perpendicular;
    }
};
