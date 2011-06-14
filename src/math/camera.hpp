#ifndef HSTEFAN_CAMERA_HPP
#define HSTEFAN_CAMERA_HPP

#include "../math/vector.hpp"

namespace hstefan
{
namespace math
{

inline mat4d cameraMatrix(vec3 eye, vec3 center, vec3 up)
{
   vec3 f = center - eye;
   f = normalize(f);
   up = normalize(up);
   vec3 s = cross(f, up);
   vec3 u = cross(s, f);

   mat4d res = {{
      s[0] ,  s[1],  s[2],  0,
      u[0] ,  u[1],  u[2],  0,
      -f[0], -f[1], -f[2],  0,
       0,       0,     0,   1
   }};

   return res;
}

} //namespace math
} //namespace hstefan

#endif