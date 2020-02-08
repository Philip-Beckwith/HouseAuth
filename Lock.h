#pragma once
#include <string>
#include <vector>

struct Client{
    std::string user = "";
    std::string key = "";
};

class Lock{
protected:
    const std::string FIREFIGHTER_KEY = "FIREFIGHTER_SECRET_KEY";
    std::vector<std::string> keys;
    Client curentClient;
    bool _isOpen = false;
protected:
    bool checkKey();
public:
    void changeKeys(std::vector<std::string> kyes);
    void insertKey(Client client);
    bool turnKey(std::string user);
    void lock();
    bool isOpen();

    std::string getUser();
    std::string getKey();
};