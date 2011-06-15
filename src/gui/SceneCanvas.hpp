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

#ifndef HSTEFAN_SCENE_CANVAS_HPP
#define HSTEFAN_SCENE_CANVAS_HPP

#include <SCV/Canvas.h>
#include "../util/TransformStack.hpp"

namespace hstefan
{
namespace gui 
{
//Classe de visualizacao
class SceneCanvas : public scv::Canvas
{
public:
   //teclas para translacao
   static const char MOVE_FORWARD_K   = 'w';
   static const char MOVE_LEFT_K      = 'a';
   static const char MOVE_BACKWARD_K  = 's';
   static const char MOVE_RIGHT_K     = 'd';
   static const char MOVE_UPWARD_K    = 'r';
   static const char MOVE_DOWNWARD_K  = 'f';

   //teclas para rotacao
   static const char CLOCKWISE_YAW_K    = 'u';
   static const char ANTICLOCKW_YAW_K   = 'i';
   static const char CLOCKWISE_PITCH_K  = 'j';
   static const char ANTICLOCKW_PITCH_K = 'k';
   static const char CLOCKWISE_ROLL_K   = 'n';
   static const char ANTICLOCKW_ROLL_K  = 'm';

   SceneCanvas(const scv::Point& po, const scv::Point& pf);

   void render(void);
   void onKeyUp(const scv::KeyEvent &evt);
   void onMouseWheel(const scv::MouseEvent &evt);
   void onKeyPressed(const scv::KeyEvent &evt);
protected:
   void loadModel();
   void loadGround();
   void initCam();
   struct Camera
   {
      math::vec3 up;
      math::vec3 center;
      math::vec3 eye;
      math::vec3 dir;
      math::vec3 right; 
   };

   void onMoveForward();
   void onMoveBackward();
   void onMoveLeft();
   void onMoveRight();
   void onMoveUpward();
   void onMoveDownward();
   
   void onYawRotationClock();
   void onYawRotationAClock();
   void onPitchRotationClock();
   void onPitchRotationAClock();
   void onRollRotationClock();
   void onRollRotationAClock();

   void rotateCamera(float xa, float ya, float za);
private:
   float pace_x;
   float pace_y;
   float pace_z;
   float yaw_angle;
   float roll_angle;
   float pitch_angle;

   util::TransformStack trans;
   util::TransformStack ground_trans;
   std::vector<math::vec3> model;
   std::vector<math::vec3> ground;
   Camera cam;
};

} //namespace gui
} //namespace hstefan

#endif