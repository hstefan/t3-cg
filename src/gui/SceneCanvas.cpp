#include "SceneCanvas.hpp"

using namespace hstefan::gui;

void SceneCanvas::update( void )
{
   //throw std::exception("The method or operation is not implemented.");
}

void SceneCanvas::render( void ) 
{
   //throw std::exception("The method or operation is not implemented.");
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