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

using namespace hstefan::gui;

SceneCanvas::SceneCanvas(const scv::Point& po, const scv::Point& pf)
   : Canvas(po, pf)
{}

void SceneCanvas::update( void )
{
   //throw std::exception("The method or operation is not implemented.");
}

void SceneCanvas::render( void ) 
{
   glColor3f(1.0f, 0.f, 0.f);
   glBegin(GL_QUADS);
      glVertex2f(200.f, 400.f);
      glVertex2f(400.f, 400.f);
      glVertex2f(400.f, 200.f);
      glVertex2f(200.f, 200.f);
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