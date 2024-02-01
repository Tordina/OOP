#pragma once
#include"IUserRepository.h"

namespace AS {
	class FileUserRepository :AS::IUserRepository {
		
	public:
		FileUserRepository();
		virtual AS::User GetById(int id) override;
		virtual AS::User GetByName(const std::string& login) override;
		virtual std::vector<AS::User> Get() const override;
		virtual void Add(AS::User item) override;
		virtual void Remove(AS::User item) override;
		virtual AS::User checkLogin();
		virtual void saveToFile() ;
		virtual int createNewId();


	protected:
		std::vector<AS::User> users;
	};

	
}
