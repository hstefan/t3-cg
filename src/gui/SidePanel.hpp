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

#ifndef HSTEFAN_SIDE_PANEL_HPP
#define HSTEFAN_SIDE_PANEL_HPP

#include <SCV/Panel.h>
#include <SCV/ButtonGroup.h>
#include <SCV/RadioButton.h>

namespace hstefan
{
namespace gui
{

class SidePanel : public scv::Panel
{
public:
   static const int PERSPECTIVE_PROJECTION_INDEX = 0;
   static const int ORTHOGRAPHIC_PROJECTION_INDEX = 1;
   
   static const int DEFAULT_MARGIN = 10;

   SidePanel(const scv::Point& po, const scv::Point& pf);
   ~SidePanel();

   void onMouseClick(const scv::MouseEvent &evt );
   inline void setOrthoFunction(void (*ortho_f)());
   inline void setPersFunction(void (*pers_f)());
private:
   scv::ButtonGroup* group; //radio buttons para selecionar o tipo da projecao
   scv::RadioButton* pers;
   scv::RadioButton* ortho;
   void (*ortho_f)();
   void (*pers_f)();
   scv::Label* label_top;
   scv::Label* label_middle;
   scv::Label* label_bottom;
   int last_choice;
};

void SidePanel::setOrthoFunction(void (*ortho_f)()) 
{
   this->ortho_f = ortho_f;
}

void SidePanel::setPersFunction(void (*pers_f)()) 
{
   this->pers_f = pers_f;
}

} //namespace gui
} //namespace hstefan

#endif