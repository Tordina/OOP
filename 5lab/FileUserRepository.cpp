
#include "FileUserRepository.h"
#include <iostream>
#include <fstream>

namespace DT {

    FileUserRepository::FileUserRepository() {
        users.clear();

        std::ifstream in("users.txt");

        if (in.is_open()) {
            DT::User user;

            while (in >> user.id >> user.login >> user.password >> user.name) {
                users.push_back(user);
            }
        }

        in.close();
    }

    DT::User FileUserRepository::GetById(int id) {
        DT::User user;

        for (const DT::User& userF : users) {
            if (userF.id == id) {
                user = userF;
                break;
            }
        }

        return user;
    }

    DT::User FileUserRepository::GetByName(const std::string& login) {
        DT::User user;

        for (const DT::User& userF : users) {
            if (userF.login == login) {
                user = userF;
                return user;
            }
        }

        return user;
    }

    std::vector<DT::User> FileUserRepository::Get() const { return users; }

    void FileUserRepository::Add(DT::User user) {
        users.push_back(user);

        saveToFile();
    }

    void FileUserRepository::Remove(DT::User user) {
        auto del = users.begin();

        while (del != users.end()) {
            if (del->id == user.id) {
                users.erase(del);
                break;
            }
            else {
                ++del;
            }
        }

        saveToFile();
    }

    DT::User FileUserRepository::checkLogin() {
 
        std::ifstream in("Authorization.txt");
        DT::User user;

        if (in.is_open()) {
            in >> user.id >> user.login >> user.password >> user.name;
            in.close();
        }

        return user;
    }

    void FileUserRepository::saveToFile() {
        std::ofstream out("users.txt");

        if (out.is_open()) {
            for (auto const& user : users) {
                out << user.id << " " << user.login << " " << user.password << " " << user.name;
            }
        }

        out.close();
    }

    int FileUserRepository::createNewId() {
        return users.size() + 1;
    }
}