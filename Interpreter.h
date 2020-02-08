#pragma once
#include <string>
#include <vector>
#include <sstream>

#include "House.h"

class Interpreter{
private:
  const std::string INSERT_KEY = "INSERT KEY";
  const std::string TURN_KEY = "TURN KEY";
  const std::string ENTER_HOUSE = "ENTER HOUSE";
  const std::string WHO_INSIDE = "WHO'S INSIDE?";
  const std::string CHANGE_LOCK= "CHANGE LOCKS";
  const std::string LEAVE_HOUSE = "LEAVE HOUSE";

  House house;

protected:
  std::vector<std::string> splitInstructions(std::string instruction);
  void preconditions(bool isValid);

  void insertKey(std::vector<std::string> instruction);
  void turnKey(std::vector<std::string> instruction);
  void enterHouse(std::vector<std::string> instruction);
  void whosInside(std::vector<std::string> instruction);
  void changeLocks(std::vector<std::string> instruction);
  void leaveHouse(std::vector<std::string> instruction);
public:
  void intInterpretConstructor(int argumentCount, char *arguments[]);
  void intInterpretInstruction(std::string instruction);
};
