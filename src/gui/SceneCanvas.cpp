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

#include "SceneCanvas.hpp"
#include "../math/projection.hpp"
#include "../math/camera.hpp"

using namespace hstefan::gui;
using namespace hstefan::math;

SceneCanvas::SceneCanvas(const scv::Point& po, const scv::Point& pf)
   : Canvas(po, pf), trans(), model()
{
   loadModel();
   initCam();
   trans.setVertexGroup(model.begin(), model.end());
}

void SceneCanvas::update( void )
{
   //throw std::exception("The method or operation is not implemented.");
}

void SceneCanvas::render( void ) 
{
   //model transform
   trans.pushScale(100, 100, 100);
   trans.pushTranslate(400, 400, 20);
   
   //view/camera transform
   trans.pushCustom(cameraMatrix(cam.eye, cam.center, cam.up));
   //projection transform
   trans.pushCustom(orthogonalProj());
   
   //divide by w
   //window transform
   mat4d mat = {{
      1, 0,     0    , 0,
      0, 1,     0    , 0,
      0, 0, 1.f/30.f , 0,
      0, 0,     0    , 1
   }};
   trans.pushCustom(mat);

   auto m = *(trans.apply());

   glColor3f(1.0f, 0.f, 0.f);

   glBegin(GL_QUADS);
      glVertex2f(m[0][0], m[0][1]);
      glVertex2f(m[1][0], m[1][1]);
      glVertex2f(m[2][0], m[2][1]);
      glVertex2f(m[0][0], m[3][1]);

      glVertex2f(m[0][0], m[0][1]);
      glVertex2f(m[4][0], m[4][1]);
      glVertex2f(m[5][0], m[5][1]);
      glVertex2f(m[1][0], m[1][1]);

      glVertex2f(m[1][0], m[1][1]);
      glVertex2f(m[5][0], m[5][1]);
      glVertex2f(m[6][0], m[6][1]);
      glVertex2f(m[2][0], m[2][1]);

      glVertex2f(m[4][0], m[4][1]);
      glVertex2f(m[5][0], m[5][1]);
      glVertex2f(m[6][0], m[6][1]);
      glVertex2f(m[7][0], m[7][1]);

      glVertex2f(m[3][0], m[3][1]);
      glVertex2f(m[7][0], m[7][1]);
      glVertex2f(m[5][0], m[5][1]);
      glVertex2f(m[2][0], m[2][1]);

      glVertex2f(m[0][0], m[0][1]);
      glVertex2f(m[4][0], m[4][1]);
      glVertex2f(m[7][0], m[7][1]);
      glVertex2f(m[3][0], m[3][1]);
   glEnd();
}

void SceneCanvas::onKeyUp( const scv::KeyEvent &evt ) 
{
   //throw std::exception("The method or operation is not implemented.");
}

void SceneCanvas::onMouseWheel( const scv::MouseEvent &evt ) 
{
   //throw std::exception("The method or operation is not implemented.");
}

void SceneCanvas::onKeyPressed( const scv::KeyEvent &evt ) 
{
   switch(evt.getKeyCode()) {
   case MOVE_FORWARD_K     : // pra frente
      break; 
   case MOVE_LEFT_K        : // pra esquerda
      break;
   case MOVE_BACKWARD_K    : // pra traz
      break; 
   case MOVE_RIGHT_K       : // pra direita
      break;
   case MOVE_UPWARD_K      : // pra cima
      break;
   case MOVE_DOWNWARD_K    : // pra baixo
      break;
   case CLOCKWISE_YAW_K    : // rotacao YAW clockwise
      break; 
   case ANTICLOCKW_YAW_K   : // rotacao YAY anticlockwise
      break;
   case CLOCKWISE_PITCH_K  : // rotacao pitch clockwise
      break; 
   case ANTICLOCKW_PITCH_K : // rotacao pitch anticlockwise
      break;
   case CLOCKWISE_ROLL_K   : // rotacao roll clockwise
      break;
   case ANTICLOCKW_ROLL_K  : // rotacao roll anticlockwise
      break;
   }
}

void SceneCanvas::loadModel()
{
   model.reserve(8);

   model.push_back(makeVec(-0.5f, 0.5f, 0.5f));
   model.push_back(makeVec(0.5f, 0.5f, 0.5f));
   model.push_back(makeVec(0.5f, -0.5f, 0.5f));
   model.push_back(makeVec(-0.5f, -0.5f, 0.5f));

   model.push_back(makeVec(-0.5f, 0.5f, -0.5f));
   model.push_back(makeVec(0.5f, 0.5f, -0.5f));
   model.push_back(makeVec(0.5f, -0.5f, -0.5f));
   model.push_back(makeVec(-0.5f, -0.5f, -0.5f));
}

void SceneCanvas::initCam()
{
   cam.up = makeVec(0.f, 1.f, 0.f);
   cam.center = makeVec(0.f, 0.f, 0.f);
   cam.eye = makeVec(0.f, 0.f, 0.f);
}