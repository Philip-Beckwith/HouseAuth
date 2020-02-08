#pragma once
#include <string>
#include <vector>
#include <cstdio>

#include "Lock.h"

class House{
private:
  std::string owner;
  std::vector<std::string> peopleInHouse;
  Lock lock;

protected:
  bool userIsInside(std::string user);
  int userIndex(std::string user);
  void removeUser(std::string user);
public:
  void setOwner(std::string owner, std::vector<std::string> keys);
  void insertKey(std::string user, std::string key);
  void turnKey(std::string user);
  void enterHouse(std::string user);
  void whosInside();
  void changeLocks(std::string user,std::vector<std::string> locks);
  void leaveHouse(std::string user);

  void ERROR();
};
