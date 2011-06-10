#include <iostream>
#include <SCV/Button.h>
#include <SCV/Kernel.h>

int main() 
{
   scv::Kernel* ker = scv::Kernel::getInstance();
   scv::ColorScheme* scheme = scv::ColorScheme::getInstance();
   scheme->loadScheme(scv::ColorScheme::clean);
   ker->setWindowSize(800, 600);

   scv::Button* b = new scv::Button(scv::Point(400, 300), "Clique!");
   ker->addComponent(b);
   ker->setFramesPerSecond(30.f);
   ker->run();
}