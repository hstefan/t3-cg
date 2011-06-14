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

#include "TransformStack.hpp"
#include "../math/transform3d.hpp"

using namespace hstefan::util;

TransformStack::TransformStack()
   : out_buff(new std::vector<vertex_type>()), vertex_buff(), transformations()
{
}

void TransformStack::pushYaw(float angle)
{
   pushCustom(math::yawRotationMatrix(angle));
}

void TransformStack::pushRoll(float angle)
{
   pushCustom(math::rollRotationMatrix(angle));
}

void TransformStack::pushPitch(float angle)
{
   pushCustom(math::pitchRotationMatrix(angle));
}

void TransformStack::pushScale(float sx, float sy, float sz)
{
   pushCustom(math::scaleMatrix(sx, sy, sz));
}

void TransformStack::pushTranslate(float tx, float ty, float tz)
{
   pushCustom(math::translationMatrix(tx, ty, tz));
}

void TransformStack::pushCustom(const transf_type& custom_transf)
{
   transformations.push(custom_transf);
}

const std::vector<TransformStack::vertex_type>* const TransformStack::apply()
{
   math::mat4d res = math::identityMatrix();
   while(!transformations.empty())
   {
      res = res * transformations.top();
      transformations.pop();
   }
   auto end_it_v = vertex_buff.end();
   out_buff->clear();
   for(auto it = vertex_buff.begin(); it != end_it_v; ++it) 
      out_buff->push_back(math::unhomogen(res*math::homogen(*it)) );

   return out_buff;
}
