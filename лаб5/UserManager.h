#pragma once
// Обеспечивает единократное включение заголовочного файла.

#include "IUserManager.h"
#include "IUserRepository.h"
#include "iostream"

class UserManager : public IUserManager
{
private:
    User* currentUser; 
    IUserRepository* userRepository; 
public:
    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr)
    {
    }

    void signIn(User& user) override
    {
        currentUser = &user; 
    }

    void signOut(User& user) override
    {
        currentUser = nullptr; 
        std::cout << "User has been signed out" << std::endl; 
    }

    bool isAuthorized() override
    {
        return currentUser != nullptr;
    }
};