#ifndef HSTEFAN_CAMERA_HPP
#define HSTEFAN_CAMERA_HPP

#include "../math/vector.hpp"

namespace hstefan
{
namespace math
{
 
inline mat4d cameraMatrix(vec3 eye, vec3 center, vec3 up, vec3* forward = 0, vec3* right = 0)
{
   vec3 f = center - eye;
   if(forward != 0)
      f = *forward;
   f = normalize(f);
   up = normalize(up);
   vec3 s = cross(f, up);
   if(right != 0)
      s = *right;
   vec3 u = cross(s, f);
   float a = dot(eye, s);
   float b = dot(eye, f);
   float c = dot(eye, up);

   mat4d res = {{
      s[0] ,  s[1],  s[2],  -a,
      u[0] ,  u[1],  u[2],  -c,
      f[0],   f[1],  f[2],  -b,
       0,       0,     0,    1
   }};

   return res;
}

} //namespace math
} //namespace hstefan

#endif