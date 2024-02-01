#include "FileUserManager.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace DT {

    FileUserManager::FileUserManager() {
        actual_user = DT::User();
    }
    void FileUserManager::SignIn(DT::User user) {

        actual_user = user;
        ofstream file("Authorization.txt");
        file << user.id << " " << user.login << " " << user.password << " " << user.name << "\n";
        file.close();
        cout << "успешная авторизация!" << endl;
    }
    void FileUserManager::SignOut()
    {
        actual_user = DT::User();
        ofstream file("Authorization.txt");

        file << "";
        file.close();

        cout << "Выход из аккаунта завершен!" << endl;
    }
    bool FileUserManager::IsAuthorized()
    {
        return !actual_user.login.empty();
    }

    void FileUserManager::SignUp(std::string login, std::string name, std::string password) {

        DT::User user = user_repository.GetByName(login);

        if (user.login.empty()) {
            DT::User newUser;

            newUser.id = user_repository.createNewId();

            newUser.login = login;
            newUser.name = name;
            newUser.password = password;

            user_repository.Add(newUser);

            cout << "Вы успешно зарегистрировали нового пользователя!" << endl;

            user_repository.saveToFile();
        }
        else {
            cout << "Пользователь с таким именем входа уже существует." << endl;
        }

    }

    void FileUserManager::Work() {

        ifstream file("Authorization.txt");

        if (file.is_open()) {
            string login, password, name;

            file >> login >> password >> name;

            DT::User user;
            user.login = login;
            user.password = password;
            user.name = name;
            actual_user = user;

            file.close();
        }

        while (true) {

            cout << "1.Войти в аккаунт" << endl;
            cout << "2.Зарегистрироваться" << endl;

            if (IsAuthorized()) {
                cout << "3.Выйти из аккаунта" << endl;
            }

            cout << "0.Выйти из программы" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                if (IsAuthorized()) {
                    SignOut();
                }
                else {
                    string login, password;
                    cout << "Введите логин: ";
                    cin >> login;
                    cout << "Введите пароль: ";
                    cin >> password;

                    User user = user_repository.GetByName(login);
                    if (!user.login.empty() && user.password == password) {
                        SignIn(user);
                    }
                    else {
                        cout << "Пользователь не найден." << endl;
                    }
                }
                break;

            case 2:
                if (IsAuthorized()) {
                    SignOut();
                }
                else {
                    string login, name, password;
                    cout << "Введите логин: ";
                    cin >> login;
                    cout << "Введите имя: ";
                    cin >> name;
                    cout << "Введите пароль: ";
                    cin >> password;

                    SignUp(login, name, password);
                }
                break;

            case 3:
                SignOut();
                break;

            case 0:
                return;
            }
        }

    }
}