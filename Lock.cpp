#include "Lock.h"

void Lock::changeKeys(std::vector<std::string> new_keys){
    keys = new_keys;
}

void Lock::insertKey(Client client){
    curentClient = client;
}

bool Lock::turnKey(std::string user){
    return _isOpen = user.compare(curentClient.user)==0 && checkKey();
}

bool Lock::checkKey(){
    for(int i =0; i<keys.size(); i++){
        if(curentClient.key.compare(keys[i])==0){
            return true;
        }
    }
    return false;
}

void Lock::lock(){
    _isOpen = false;
}

bool Lock::isOpen(){
    return _isOpen;
}


std::string Lock::getUser(){return curentClient.user;}
std::string Lock::getKey(){return curentClient.key;}