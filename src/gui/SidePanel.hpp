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

template <void F(), void G()> //T seria a funcao/classe 
class SidePanel : public scv::Panel
{
public:
   static const int PERSPECTIVE_PROJECTION_INDEX = 0;
   static const int ORTHOGRAPHIC_PROJECTION_INDEX = 1;
   
   static const int DEFAULT_MARGIN = 20;

   SidePanel(const scv::Point& po, const scv::Point& pf);

   void onMouseUp( const scv::MouseEvent &evt ) {}
private:
   scv::ButtonGroup group; //radio buttons para selecionar o tipo da projecao
   scv::RadioButton* pers;
   scv::RadioButton* ortho;
   scv::Label* label;
   int last_choice;
};

template <typename F, typename G>
SidePanel<F,G>::SidePanel(const scv::Point& po, const scv::Point& pf)
   : scv::Panel(po, pf), group(), pers(0), ortho(0), label(0), last_choice(0)
{
   last_choice = -1;
   scv::Point p = po;
   p.translateX(DEFAULT_MARGIN);
   p.translateY(DEFAULT_MARGIN);
   pers = new scv::RadioButton(p, true,  "Perspectiva");
   p.translateY(pers.getHeight() + DEFAULT_MARGIN);
   ortho = new  scv::RadioButton(p, false, "Ortogonal");
   p.translateY(-(pers->getHeight() + DEFAULT_MARGIN));
   label = new scv::Label (p, "W/S - Frente/Tras         U/I - Yaw horario/anti\n" +
                              "A/D - Direita/Esquerda    J/K - Pitch horario/anti\n" + 
                              "R/F - Cima/Baixo          N/M - Roll horario/anti\n");
   group._componentsArray.push_back(pers);
   group._componentsArray.push_back(ortho);
   addComponent(pers);
   addComponent(ortho);
   addComponent(label);
   F();
}

} //namespace gui
} //namespace hstefan

#endif