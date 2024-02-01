#pragma once
#include"IDataRepository.h"
#include"User.h"

namespace AS {
	class IUserRepository: AS::IDataRepository<AS::User> {
	public:
		virtual AS::User GetById(int id) =0;
		virtual AS::User GetByName(const std::string& login)=0;
	
	};
}
