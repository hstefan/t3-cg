/**********************************************************************************
 * Copyright (C) 2011 by Hugo Stefan Kaus Puhlmann                                *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      *
 * copies of the Software, and to permit persons to whom the Software is          * 
 * furnished to do so, subject to the following conditions:                       *
 *                                                                                *
 * The above copyright notice and this permission notice shall be included in     *
 * all copies or substantial portions of the Software.                            *
 *                                                                                *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN      *
 * THE SOFTWARE.                                                                  *
 *********************************************************************************/
/*
 * Nome: Hugo Stefan Kaus Puhlmann
 * Matricula: 2910182
 */
#ifndef HSTEFAN_VECTOR_HPP
#define HSTEFAN_VECTOR_HPP

#include "matrix.hpp"
#include "math.hpp"
#include <cmath>

namespace hstefan
{
namespace math
{
typedef matrix<4, 1> vec4;
typedef matrix<3, 1> vec3;
typedef matrix<2, 1> vec2;

template<unsigned int N>
float dot(const matrix<N, 1>& v1, const matrix<N, 1>& v2)
{
   float ret = 0;
   for(unsigned int i = 0; i < N; i++)
   {
      ret += v1.data[i] * v2.data[i];
   }
   return ret;
}

inline vec3 cross(const vec3& v, const vec3& u)
{
   vec3 res = {{
      v[1]*u[2] - u[1]*v[2],
      v[2]*u[0] - u[2]*v[0],
      v[0]*u[1] - u[0]*v[1]
   }};

   return res;
}

template<unsigned int N>
float norm(const matrix<N, 1>& vec)
{
   float acc = 0;

   for(unsigned int i = 0; i < N; ++i)
      acc += vec[i] * vec[i];

   return 1/invSqrt(acc);
}

template<unsigned int N>
matrix<N, 1>& normalize(matrix<N, 1>& vec)
{
   float s = 0;
   for(unsigned int i = 0; i < N; ++i)
      s += vec[i] * vec[i];
   vec *= math::invSqrt(s);
   return vec;
}

template<unsigned int N>
matrix<N, 1> unit(const matrix<N, 1>& vec)
{
   float s = 0;
   for(unsigned int i = 0; i < N; ++i)
      s += vec[i] * vec[i];
   return vec * math::invSqrt(s);
}

inline char quadrant(const vec2& vec)
{
   char quad = 1;
   if(vec[0] < 0 && vec[1] > 0)
      quad = 2;
   else if (vec[0] < 0 && vec[1] < 0)
      quad = 3;
   else if (vec[0] > 0 && vec[1] < 0)
      quad = 4;
   return quad;
}

inline vec2 makeVec(float x, float y)
{
   vec2 v = {{x, y}};
   return v;
}

inline vec3 makeVec(float x, float y, float z)
{
   vec3 v = {{x, y, z}};
   return v;
}

inline vec4 makeVec(float x, float y, float z, float h)
{
   vec4 v = {{x, y, z, h}};
   return v;
}

inline float angle2dh(const vec2 v, const vec2 u)
{
   float dt = dot(v, u);
   float n = norm(v) * norm(u);
   
   return acos(dt/n);
}
template <unsigned int M>
inline matrix<M + 1, 1> homogen(const matrix<M, 1>& v, float w = 1)
{
   matrix<M + 1, 1> res;
   for(unsigned int i = 0; i < M; ++i)
      res[i] = v[i];
   res[M] = w;
   return res;
}

template <unsigned int M>
inline matrix<M - 1, 1> unhomogen(const matrix<M, 1>& v)
{
   matrix<M - 1, 1> res;
   for(unsigned int i = 0; i < M - 1; ++i)
      res[i] = v[i]/v[M - 1];
   return res;
}

/*
template <unsigned int M>
matrix<M - 1, 1> operator matrix<M, 1>(const matrix<M, 1>& v)
{
   matrix<M - 1, 1> res;
   for(unsigned int i = 0; i < M - 1; ++i)
      res[i] = v[i];
   return res;
}*/


} //namespace math
} //namespace hstefan
#ifdef _DEBUG
#include <ostream>
template <unsigned int M, unsigned int N>
std::ostream& operator<<(std::ostream& out, const hstefan::math::matrix<M, N>& m)
{
	out << "(";
	for(unsigned int i = 0; i < M; ++i)
	{
		out << m[i];
		if(i + 1 == M)
			out << ")";
		else
			out << ",";
	}

	return out;
}
#endif

#endif
