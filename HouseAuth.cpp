#include "Interpreter.h"
#include <iostream>

int main(int argc, char *argv[]){
  Interpreter interpreter;
  std::string instruction;

  interpreter.intInterpretConstructor(argc, argv);
  while(std::getline(std::cin, instruction)){
    interpreter.intInterpretInstruction(instruction);
  }

  return  0;
}
