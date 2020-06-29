//
//  Geometry.h
//  RayTracer
//
//  Created by Samuel Parmer on 6/16/20.
//  Copyright © 2020 Samuel Parmer. All rights reserved.
//

#ifndef Geometry_h
#define Geometry_h

#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

//generic template for n-dimensional vectors with overloads
template <size_t dimension, typename T> struct vec{
    vec() {for(size_t i = dimension; i--; data_[i] = T());}
    
    T& operator[] (const size_t i){assert(i<dimension); return data_[i];}
    const T& operator[] (const size_t i) const {assert(i<dimension); return data_[i];}
    
private:
    T data_[dimension];
    };

typedef vec<2, float> Vec2f;
typedef vec<3, float> Vec3f;
typedef vec<3, int> Vec3i;
typedef vec<4, float> Vec4f;


template <typename T> struct vec<2,T> {
    vec() : x(T()), y(T()) {}
    vec(T X, T Y) : x(X), y(Y) {}
    template <class U> vec<2,T>(const vec<2,U> &v);
          T& operator[](const size_t i){ assert(i<2); return i<=0 ? x : y; }
    const T& operator[](const size_t i) const { assert(i<2); return i<=0 ? x : y; }
    T x,y;
};

template <typename T> struct vec<3,T>{
    vec(): x(T()), y(T()), z(T()), {} //empty init
    vec(T X, T Y, T Z) : x(X), y(Y), z(Z);
    
    T& operator[](const size_t i){assert(i<3); return i<=0 ? x : (1==i ? y : z);}
    const T& operator[](const size_t i) const {assert(i<3); return i<=0 ? x : (1==i ? y : z);}
    
    float norm(){return std::sqrt(x*x+y*y+z*z);}
    
    vec<3,T> & normalize(T l=1) { *this = (*this)*(l/norm()); return *this; }
       T x,y,z;
};

#endif /* Geometry_h */
