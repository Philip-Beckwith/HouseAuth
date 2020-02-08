#include "Interpreter.h"
#include <iostream>

void Interpreter::intInterpretConstructor(int argumentCount, char *arguments[]){
  try{
  std::vector<std::string> keys;
  std::string owner = arguments[1];
  preconditions(argumentCount > 2);

  for(int i=2; i<argumentCount; i++){
    keys.push_back(arguments[i]);
  }
  house.setOwner(owner,keys);
  }catch(...){
    house.ERROR();
  }
}

void Interpreter::intInterpretInstruction(std::string instruction){
  try{
      if(instruction.rfind(INSERT_KEY, 0) ==0){insertKey(splitInstructions(instruction));}
  else if(instruction.rfind(TURN_KEY, 0) ==0){turnKey(splitInstructions(instruction));}
  else if(instruction.rfind(ENTER_HOUSE, 0) ==0){enterHouse(splitInstructions(instruction));}
  else if(instruction.rfind(WHO_INSIDE, 0) ==0){whosInside(splitInstructions(instruction));}
  else if(instruction.rfind(CHANGE_LOCK, 0) ==0){changeLocks(splitInstructions(instruction));}
  else if(instruction.rfind(LEAVE_HOUSE, 0) ==0){leaveHouse(splitInstructions(instruction));}
  else {preconditions(false);}
  }catch(...){
    house.ERROR();
  }
}

void Interpreter::insertKey(std::vector<std::string> instruction){
  preconditions(instruction.size() == 4);
  std::string user = instruction[2];
  std::string key = instruction[3];
  house.insertKey(user, key);
}

void Interpreter::turnKey(std::vector<std::string> instruction){
  preconditions(instruction.size() == 3);
  std::string user = instruction[2];
  house.turnKey(user);
}

void Interpreter::enterHouse(std::vector<std::string> instruction){
  preconditions(instruction.size() == 3);
  std::string user = instruction[2];
  house.enterHouse(user);
}

void Interpreter::whosInside(std::vector<std::string> instruction){
  preconditions(instruction.size() == 2);
  house.whosInside();
}

void Interpreter::changeLocks(std::vector<std::string> instruction){
  preconditions(instruction.size() >2);
  std::string assumedOwner = instruction[2];
  std::vector<std::string> newKeys;

  for(int i=3; i<instruction.size(); i++){
    newKeys.push_back(instruction[i]);
  }
  house.changeLocks(assumedOwner, newKeys);
}

void Interpreter::leaveHouse(std::vector<std::string> instruction){
  preconditions(instruction.size() == 3);
  std::string user = instruction[2];
  house.leaveHouse(user);
}

std::vector<std::string> Interpreter::splitInstructions(std::string instruction){
  std::vector<std::string> instructions;
  std::stringstream stream(instruction);
  std::string token;

  while(std::getline(stream, token, ' ')){
    instructions.push_back(token);
  }
  return instructions;
}

void Interpreter::preconditions(bool isValid){
  if(!isValid){
    throw;
  }
}