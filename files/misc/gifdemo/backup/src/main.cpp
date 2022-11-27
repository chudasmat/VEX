/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       james                                                     */
/*    Created:      Thu Mar 21 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "gifclass.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

int main() {
  int count = 0;

  vex::Gif gif("world.gif", 120, 0 );
  
  while(1) {
    Brain.Screen.printAt( 5, 230, "render %d", count++ );
    Brain.Screen.render();
  }
}