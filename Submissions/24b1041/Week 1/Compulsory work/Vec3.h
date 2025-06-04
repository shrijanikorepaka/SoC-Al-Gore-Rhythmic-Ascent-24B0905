$ifndef VEC3_H
#define VEC3_H

#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;
class Vec3{
    public:
        float a;
        float b;
        float c;
        Vec3(){};
        Vec3(float x, float y, float z){
            a=x;
            b=y;
            c=z;
        }
        Vec3 operator+(const Vec3& other);
        Vec3 operator-(const Vec3& other);
        Vec3 operator*(double x);
        friend Vec3 operator*(double x, Vec3& V);
        Vec3 operator/(double x);
        Vec3 operator-();
        float& operator[](int index);

        Vec3 unit() const;
        double length() const;
        double dot(const Vec3& other) const;
        Vec3 cross(const Vec3& other);
        Vec3 reflect(const Vec3& normal) const;
        Vec3 refract(const Vec3& normal, float refractive_index) const;
        void print()const;
};
#endif
