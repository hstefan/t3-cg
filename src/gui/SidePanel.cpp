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

#include "SidePanel.hpp"
#include "ProjRadioButton.hpp"
#include <algorithm>
#include "ProjRadioButton.hpp"
using namespace hstefan::gui;

SidePanel::SidePanel(const scv::Point& po, const scv::Point& pf, SceneCanvas* canvas)
   : scv::Panel(po, pf), group(new scv::ButtonGroup()), pers(0), ortho(0), ortho_f(0), 
   pers_f(0), label_top(0), label_middle(0), label_bottom(0), last_choice(0)
{
   last_choice = -1;
   scv::Point p(0, 0);
   p.translateX(DEFAULT_MARGIN);
   p.translateY(DEFAULT_MARGIN);
   pers = new ProjRadioButton(p, "Pespectiva", true, canvas, ProjRadioButton::PESPECTIVE);
   p.translateY(pers->getHeight() + DEFAULT_MARGIN);
   ortho = new ProjRadioButton(p, "Ortografica", false, canvas, ProjRadioButton::ORTHOGONAL);
   p.translateY(-(pers->getHeight() + DEFAULT_MARGIN));

   p.translateX(std::max(pers->getWidth(), ortho->getWidth()) + 30);
   label_top = new scv::Label (p, "W/S - Frente/Tras         U/I - Yaw horario/anti");
   p.translateY(label_top->getHeight());
   label_middle = new scv::Label (p, "A/D - Direita/Esquerda    J/K - Pitch horario/anti");
   p.translateY(label_middle->getHeight());
   label_bottom = new scv::Label(p, "R/F - Cima/Baixo          N/M - Roll horario/anti");

   pers->registerButtonGroup(group);
   ortho->registerButtonGroup(group);
   addComponent(pers);
   addComponent(ortho);
   addComponent(label_top);
   addComponent(label_middle);
   addComponent(label_bottom);
}

SidePanel::~SidePanel() 
{
   delete group;
   delete pers;
   delete ortho;
   delete label_top;
   delete label_middle;
   delete label_bottom;
}

void SidePanel::onMouseClick(const scv::MouseEvent &evt) 
{
   std::cout << "Foo" << std::endl;
   if(pers->getState() == true && last_choice != PERSPECTIVE_PROJECTION_INDEX)
   {
      if(pers_f != 0)
      {
         pers_f();
         last_choice = PERSPECTIVE_PROJECTION_INDEX;
      }
   }
   else if (ortho->getState() == true && last_choice != ORTHOGRAPHIC_PROJECTION_INDEX)
   {
      if(ortho_f != 0)
      {
         ortho_f();
         last_choice = ORTHOGRAPHIC_PROJECTION_INDEX;
      }
   }
}