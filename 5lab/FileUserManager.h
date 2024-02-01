#pragma once
#include"IUserManager.h"
#include"FileUserRepository.h"

namespace AS {
	class FileUserManager :AS::IUserManager {
	public:

		FileUserManager();

		virtual void SignIn(AS::User user) override;
		virtual void SignOut() override;
		virtual bool IsAuthorized() override;
		virtual void Work() override;
		virtual void SignUp(std::string name, std::string login, std::string password) override;


	private:
		AS::User actual_user;
		AS::FileUserRepository user_repository;
	

	};
}