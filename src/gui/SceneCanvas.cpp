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
#include "../math/transform3d.hpp"

using namespace hstefan::gui;
using namespace hstefan::math;

SceneCanvas::SceneCanvas(const scv::Point& po, const scv::Point& pf)
   : Canvas(po, pf), trans(), model(), pace_x(0.7f), pace_y(0.7f), pace_z(5.f), yaw_angle(3.1415f/50.f), 
   roll_angle(3.1415f/50.f), pitch_angle(3.1415f/50.f)
{
   loadModel();
   loadGround();
   initCam();
   trans.setVertexGroup(model.begin(), model.end());
   ground_trans.setVertexGroup(ground.begin(), ground.end());
}

void SceneCanvas::render( void ) 
{
   glColor3f(0.f, 0.f, 0.f);
   glBegin(GL_QUADS);
      glVertex2f(0.f, 0.f);
      glVertex2f(800.f, 0.f);
      glVertex2f(800.f, 600.f);
      glVertex2f(0.f, 600.f);
   glEnd();
   
   ground_trans.pushScale(800.f, 1.f, 800.f);
   ground_trans.pushTranslate(400.f, 300.f, 0.f);
   ground_trans.pushCustom(cameraMatrix(cam.eye, cam.center, cam.up, &cam.dir, &cam.right));
   ground_trans.pushCustom(perspecProj(1.f/800.f));
   auto g = *ground_trans.apply();
   glColor3f(34.f/255.f, 139.f/255.f, 34.f/255.f);
   glBegin(GL_QUADS);
      glVertex2f(g[0][0], g[0][1]);
      glVertex2f(g[1][0], g[1][1]);
      glVertex2f(g[2][0], g[2][1]);
      glVertex2f(g[3][0], g[3][1]);
   glEnd();

   trans.pushScale(60.f, 60.f, 60.f);
   trans.pushTranslate(400.f, 300.f, 0.f);
   trans.pushTranslate(0.f, 30.f, 0.f);
   trans.pushCustom(cameraMatrix(cam.eye, cam.center, cam.up, &cam.dir, &cam.right));
   trans.pushCustom(perspecProj(1.f/800.f));

   auto m = *(trans.apply());

   glColor3f(178.f/255.f, 34.f/255.f, 34.f/255.f);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glLineWidth(2.0f);
   glBegin(GL_QUADS);
      glVertex2f(m[0][0], m[0][1]);
      glVertex2f(m[1][0], m[1][1]);
      glVertex2f(m[2][0], m[2][1]);
      glVertex2f(m[3][0], m[3][1]);

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
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
      onMoveForward();
      break; 
   case MOVE_LEFT_K        : // pra esquerda
      onMoveLeft();
      break;
   case MOVE_BACKWARD_K    : // pra traz
      onMoveBackward();
      break; 
   case MOVE_RIGHT_K       : // pra direita
      onMoveRight();
      break;
   case MOVE_UPWARD_K      : // pra cima
      onMoveUpward();
      break;
   case MOVE_DOWNWARD_K    : // pra baixo
      onMoveDownward();
      break;
   case CLOCKWISE_YAW_K    : // rotacao YAW clockwise
      onYawRotationClock();
      break; 
   case ANTICLOCKW_YAW_K   : // rotacao YAY anticlockwise
      onYawRotationAClock();
      break;
   case CLOCKWISE_PITCH_K  : // rotacao pitch clockwise
      onPitchRotationClock();
      break; 
   case ANTICLOCKW_PITCH_K : // rotacao pitch anticlockwise
      onPitchRotationAClock();
      break;
   case CLOCKWISE_ROLL_K   : // rotacao roll clockwise
      onRollRotationClock();
      break;
   case ANTICLOCKW_ROLL_K  : // rotacao roll anticlockwise
      onRollRotationAClock();
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

void SceneCanvas::loadGround()
{   
   ground.reserve(4);
   ground.push_back(makeVec(-0.5f, 0.f, 0.5f));
   ground.push_back(makeVec(0.5f , 0.f, 0.5f));
   ground.push_back(makeVec(0.5f, 0.f, -0.5f));
   ground.push_back(makeVec(-0.5f, 0.f, -0.5f));
}

void SceneCanvas::initCam()
{
   cam.up = makeVec(0.f, 1.f, 0.f);
   cam.center = makeVec(0.f, 0.f, 0.f);
   cam.eye = makeVec(0.f, 0.f, 1.f);
   cam.dir = normalize(cam.center - cam.eye);
   cam.right = normalize(cross(cam.dir, cam.up));
}


void SceneCanvas::onMoveForward()
{
   cam.eye += normalize(cam.dir)*pace_z;
}

void SceneCanvas::onMoveBackward()
{
   cam.eye -= normalize(cam.dir)*pace_z;
}

void SceneCanvas::onMoveLeft()
{
   cam.eye -= normalize(cam.right)*pace_z;
}
void SceneCanvas::onMoveRight()
{
   cam.eye += normalize(cam.right)*pace_z;
}
void SceneCanvas::onMoveUpward()
{
   cam.eye += normalize(cam.up)*pace_z;
}
void SceneCanvas::onMoveDownward()
{
   cam.eye -= normalize(cam.up)*pace_z;
}

void SceneCanvas::onYawRotationClock()
{
   rotateCamera(0.f, -yaw_angle, 0.f);
}

void SceneCanvas::onYawRotationAClock()
{
   rotateCamera(0.f, yaw_angle, 0.f);
}

void SceneCanvas::onPitchRotationClock()
{
   rotateCamera(0.f, 0.f, -pitch_angle);
}

void SceneCanvas::onPitchRotationAClock()
{
   rotateCamera(0.f, 0.f, -pitch_angle);
}

void SceneCanvas::onRollRotationClock()
{
   rotateCamera(-roll_angle, 0.f, 0.f);
}

void SceneCanvas::onRollRotationAClock()
{
   rotateCamera(roll_angle, 0.f, 0.f);
}

void SceneCanvas::rotateCamera(float xa, float ya, float za)
{
   mat4d res = pitchRotationMatrix(za)*yawRotationMatrix(ya)*rollRotationMatrix(xa);
   cam.dir = unhomogen(res*homogen(cam.dir));
   cam.up = unhomogen(res*homogen(cam.up));
   cam.right = unhomogen(res*homogen(cam.right));
}
