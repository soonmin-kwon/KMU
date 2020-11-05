#ifndef KMUCS_GRAPHICS_TRANSFORM_HPP
#define KMUCS_GRAPHICS_TRANSFORM_HPP

#include <cmath>
#include "vec.hpp"
#include "mat.hpp"
#include "operator.hpp"

namespace kmuvcl
{
    namespace math
    {
#ifndef M_PI
        const float M_PI = 3.14159265358979323846f;
#endif

        template <typename T>
        mat<4, 4, T> translate(T dx, T dy, T dz)
        {
            mat<4, 4, T> translateMat;


            translateMat(0, 0) = 1;
            translateMat(1, 1) = 1;
            translateMat(2, 2) = 1;
            translateMat(3, 3) = 1;
            translateMat(0, 3) = dx;
            translateMat(1, 3) = dy;
            translateMat(2, 3) = dz;

            return translateMat;
        }

        template <typename T>
        mat<4, 4, T> rotate(T angle, T x, T y, T z)
        {
            mat<4, 4, T> rotateMat;

            T radianAngle = angle * (M_PI / 180);
            double dx, dy, dz;
            dx = x / (sqrt(x * x + y *y + z * z));
            dy = y / (sqrt(x * x + y *y + z * z));
            dz = z / (sqrt(x * x + y *y + z * z));
            rotateMat(0, 0) = cos(radianAngle) + dx * dx * (1 - cos(radianAngle));
            rotateMat(0, 1) = dx * dy * (1 - cos(radianAngle)) - dz * sin(radianAngle);
            rotateMat(0, 2) = dx * dz * (1 - cos(radianAngle)) + dy * sin(radianAngle);
            rotateMat(1, 0) = dy * dx * (1 - cos(radianAngle)) + dz * sin(radianAngle);
            rotateMat(1, 1) = cos(radianAngle) + dy * dy * (1 - cos(radianAngle));
            rotateMat(1, 2) = dy * dz * (1 - cos(radianAngle)) - dx * sin(radianAngle);
            rotateMat(2, 0) = dz * dx * (1 - cos(radianAngle)) - dy * sin(radianAngle);
            rotateMat(2, 1) = dz * dy * (1 - cos(radianAngle)) + dx * sin(radianAngle);
            rotateMat(2, 2) = cos(radianAngle) + dz * dz * (1 - cos(radianAngle));
            rotateMat(3, 3) = 1;

            return rotateMat;
        }

        template<typename T>
        mat<4, 4, T> scale(T sx, T sy, T sz)
        {
            mat<4, 4, T> scaleMat;
            scaleMat(0, 0) = sx;
            scaleMat(1, 1) = sy;
            scaleMat(2, 2) = sz;
            scaleMat(3, 3) = 1;

            return scaleMat;
        }

        template<typename T>
        mat<4, 4, T> lookAt(T eyeX, T eyeY, T eyeZ, T centerX, T centerY, T centerZ, T upX, T upY, T upZ)
        {
            mat<4, 4, T> m, v;
	    //set T inverse matrix
            v(0, 0) = 1;
            v(0, 3) = -eyeX;
            v(1, 1) = 1;
            v(1, 3) = -eyeY;
            v(2, 2) = 1;
            v(2, 3) = -eyeZ;
            v(3, 3) = 1;
	    
	    //set camera z-axis
            T x = centerX - eyeX;
            T y = centerY - eyeY;
            T z = centerZ - eyeZ;
	    vec<3, T> zvec(x, y, z);
            T zLen = sqrt(x * x + y * y + z * z);
            x /= zLen;
            y /= zLen;
            z /= zLen;

	    //set camera x-axis
            vec<3, T> upvec(upX, upY, upZ);
            vec<3, T> xvec = cross(zvec, upvec);
            T xLen = sqrt(dot(xvec, xvec));
            m(0, 0) = xvec(0) / xLen;
            m(0, 1) = xvec(1) / xLen;
            m(0, 2) = xvec(2) / xLen;

	    //set camera y-axis
            vec<3, T> yvec = cross(xvec, zvec);
            T yLen = sqrt(dot(yvec, yvec));
            m(1, 0) = yvec(0) / yLen;
            m(1, 1) = yvec(1) / yLen;
            m(1, 2) = yvec(2) / yLen;

            m(2, 0) = -x;
            m(2, 1) = -y;
            m(2, 2) = -z;

            m(3, 3) = 1; //set R inverse matrix

            return m*v;
        }

        template<typename T>
        mat<4, 4, T> ortho(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
            mat<4, 4, T> orthoMat;
            orthoMat(0, 0) = 2 / (right - left);
            orthoMat(0, 3) = -(right + left) / (right - left);
            orthoMat(1, 1) = 2 / (top - bottom);
            orthoMat(1, 3) = -(top + bottom) / (top - bottom);
            orthoMat(2, 2) = -2 / (farVal - nearVal);
            orthoMat(2, 3) = -(farVal + nearVal) / (farVal - nearVal);
            orthoMat(3, 3) = 1;

            return orthoMat;
        }

        template<typename T>
        mat<4, 4, T> frustum(T left, T right, T bottom, T top, T nearVal, T farVal)
        {
           mat<4, 4, T> frustumMat;
           frustumMat(0, 0) = 2 * nearVal / (right - left);
           frustumMat(0, 2) = (right + left) / (right - left);
           frustumMat(1, 1) = 2 * nearVal / (top - bottom);
           frustumMat(1, 2) = (top + bottom) / (top - bottom);
           frustumMat(2, 2) = -(farVal + nearVal) / (farVal - nearVal);
           frustumMat(2, 3) = -2 * farVal * nearVal / (farVal - nearVal);
           frustumMat(3, 2) = -1;

           return frustumMat;
        }

        template<typename T>
        mat<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
        {
          fovy = fovy / 2 * M_PI / 180;
          T top = tan(fovy) * zNear;
          T right = top * aspect;
          return frustum(-right, right, -top, top, zNear, zFar);
        }
    }
}
#endif
