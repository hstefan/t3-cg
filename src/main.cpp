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

#include <SCV/Button.h>
#include <SCV/Kernel.h>
#include "gui/SceneCanvas.hpp"
#include "gui/SidePanel.hpp"
#include <iostream>

void test()
{
   std::cout << "Hey there." << std::endl;
}

int main() 
{
   scv::Kernel* ker = scv::Kernel::getInstance();
   scv::ColorScheme* scheme = scv::ColorScheme::getInstance();
   scheme->loadScheme(scv::ColorScheme::clean);
   ker->setWindowSize(800, 600);
   hstefan::gui::SidePanel* panel = new hstefan::gui::SidePanel(scv::Point(10, 600 - 65), scv::Point(375, 600 - 10));
   hstefan::gui::SceneCanvas* canvas = new hstefan::gui::SceneCanvas(scv::Point(0,0), scv::Point(800, 600));
   panel->setOrthoFunction(&test);
   panel->setPersFunction(&test);
   //scv::Button* b = new scv::Button(scv::Point(400, 300), "Clique!");
   //ker->addComponent(b);
   ker->addComponent(canvas);
   ker->addComponent(panel);
   ker->setFramesPerSecond(30.f);
   ker->run();
}