#pragma once
#include"IUserRepository.h"

namespace DT {
	class FileUserRepository :DT::IUserRepository {

	public:
		FileUserRepository();
		virtual DT::User GetById(int id) override;
		virtual DT::User GetByName(const std::string& login) override;
		virtual std::vector<DT::User> Get() const override;
		virtual void Add(DT::User item) override;
		virtual void Remove(DT::User item) override;
		virtual DT::User checkLogin();
		virtual void saveToFile();
		virtual int createNewId();


	protected:
		std::vector<DT::User> users;
	};


}