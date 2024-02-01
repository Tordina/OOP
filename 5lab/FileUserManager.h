#pragma once
#include"IUserManager.h"
#include"FileUserRepository.h"

namespace DT {
	class FileUserManager :DT::IUserManager {
	public:

		FileUserManager();

		virtual void SignIn(DT::User user) override;
		virtual void SignOut() override;
		virtual bool IsAuthorized() override;
		virtual void Work() override;
		virtual void SignUp(std::string name, std::string login, std::string password) override;


	private:
		DT::User actual_user;
		DT::FileUserRepository user_repository;
	

	};
}