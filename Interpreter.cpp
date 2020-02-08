#include "Interpreter.h"

#include <iostream>

void Interpreter::intInterpretInstruction(std::string instruction){

      if(instruction.rfind("INSERT KEY", 0) ==0){}
  else if(instruction.rfind("TURN KEY", 0) ==0){}
  else if(instruction.rfind("ENTER HOUSE", 0) ==0){}
  else if(instruction.rfind("WHO'S INSIDE?", 0) ==0){}
  else if(instruction.rfind("CHANGE LOCKS", 0) ==0){}
  else if(instruction.rfind("LEAVE HOUSE", 0) ==0){}
}

void Interpreter::intInterpretConstructor(int argumentCount, char *arguments[]){
  for(int i=0; i<argumentCount; i++){
    std::cout<<arguments[i];
  }
}
