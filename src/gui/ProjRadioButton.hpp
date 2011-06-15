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

#ifndef HSTEFAN_PROJRADIOBUTTON_HPP
#define HSTEFAN_PROJRADIOBUTTON_HPP

#include <SCV/Panel.h>
#include <SCV/ButtonGroup.h>
#include <SCV/RadioButton.h>
#include "../gui/SceneCanvas.hpp"

namespace hstefan
{
namespace gui
{

class ProjRadioButton : public scv::RadioButton
{
private:
   SceneCanvas* canvas;
   char type;
public:
   static const char PESPECTIVE = 0;
   static const char ORTHOGONAL = 1;
   
   void onMouseClick( const scv::MouseEvent &evt ) 
   {
      if(type == PESPECTIVE)
         canvas->onPerspectiveSelection();
      else if (type == ORTHOGONAL)
         canvas->onOrtoghonalSelection();
   }

  ProjRadioButton(scv::Point pos, std::string title, bool state, SceneCanvas* canvas, char type)
     : scv::RadioButton(pos, state, title), canvas(canvas), type(type)
  {}
};

}
}

#endif
