#pragma once
#include<string>
#include"User.h"
using namespace std;
namespace DT {
	class IUserManager {
	public:
		virtual void SignIn(DT::User user)=0;
		virtual void SignOut()=0;
		virtual bool IsAuthorized()=0;
		virtual void SignUp(std::string login, std::string name, std::string password) = 0;
		virtual void Work()=0;
		

	};
}