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

#ifndef HSTEFAN_TRANSFORM_STACK_HPP
#define HSTEFAN_TRANSFORM_STACK_HPP

#include <stack>
#include <vector>
#include "../math/vector.hpp"

namespace hstefan
{
namespace util
{

class TransformStack
{
public:
   typedef math::vec3 vertex_type;
   typedef math::mat4d transf_type;

   template <class InputIterator>
   TransformStack(InputIterator begin, InputIterator end);

   TransformStack();

   template <class InputIterator>
   void setVertexGroup(InputIterator begin, InputIterator end);

   void pushYaw(float angle);
   void pushRoll(float angle);
   void pushPitch(float angle);
   //void pushProjection(); //TODO
   void pushScale(float sx, float sy, float sz);
   void pushTranslate(float tx, float ty, float tz);
   void pushTranslate(const math::vec3& v);
   void pushCustom(const transf_type& custom_transf);
   const std::vector<vertex_type>* const apply();
private:
   std::vector<vertex_type>* out_buff;
   std::vector<vertex_type> vertex_buff;
   std::stack<transf_type> transformations;
};

template <class InputIterator>
TransformStack::TransformStack(InputIterator begin, InputIterator end)
   : out_buff(0), vertex_buff(begin, end), transformations()  
{
   out_buff = new std::vector<vertex_type>();
   out_buff->reserve(vertex_buff.size());
   //transformations.push(math::identityMatrix());
}

template <class InputIterator>
void TransformStack::setVertexGroup(InputIterator begin, InputIterator end)
{
   vertex_buff.clear();
   vertex_buff.assign(begin, end);
   out_buff->resize(vertex_buff.size());
}

} //namespace util
} //namespace hstefanj

#endif