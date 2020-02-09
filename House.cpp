#include "House.h"
#include <iostream>

void House::setOwner(std::string new_owner, std::vector<std::string> keys){
    owner = new_owner;
    lock.changeKeys(keys);
}

void House::insertKey(std::string user, std::string key){
    Client client;
    client.user = user;
    client.key = key;

    lock.insertKey(client);
    printf("KEY %s INSERTED BY %s\n", key.c_str(), user.c_str());
}

void House::turnKey(std::string user){
    if(lock.turnKey(user))
    {printf("SUCCESS %s TURNS KEY %s\n", user.c_str(), lock.getKey().c_str());}
    
    else
    {printf("FAILURE %s UNABLE TO TURN KEY %s\n",user.c_str(), lock.getKey().c_str());}
}

void House::enterHouse(std::string user){
    if(lock.isOpen()){
        peopleInHouse.push_back(user);
        lock.lock();
        printf("ACCESS ALLOWED\n");
    }
    else{printf("ACCESS DENIED\n");}
}
void House::whosInside(){
    if(peopleInHouse.size() ==0){
        printf("NOBODY HOME\n");
    }
    else{
        for(int i=0; i<peopleInHouse.size()-1; i++){
            printf("%s, ", peopleInHouse[i].c_str());
        }
        printf("%s\n",peopleInHouse[peopleInHouse.size()-1].c_str());
    }
}
void House::changeLocks(std::string user,std::vector<std::string> locks){
    if(user.compare(owner) == 0 && userIsInside(owner)){
        lock.changeKeys(locks);
        printf("OK\n");
    }
    else{
        printf("ACCESS DENIED\n");
    }
}

void House::leaveHouse(std::string user){
    if(userIsInside(user)){
        
        printf("OK");
    }else{
        printf("%s NOT HERE\n", user.c_str());
    }
}

bool House::userIsInside(std::string user){
    if(userIsInside(user) == -1){return false;}
    return true;
}

int House::userIndex(std::string user){
    int index = -1;
    for(int i=0; i<peopleInHouse.size(); i++){
        if(user.compare(peopleInHouse[i])==0){
            index = i;
        }
    }
    return index;
}

void House::removeUser(std::string user){
    peopleInHouse.erase(peopleInHouse.begin()+userIndex(user));
}

void House::ERROR(){
    printf("ERROR\n");
}