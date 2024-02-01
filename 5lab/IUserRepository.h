#pragma once
#include"IDataRepository.h"
#include"User.h"

namespace DT {
	class IUserRepository: DT::IDataRepository<DT::User> {
	public:
		virtual DT::User GetById(int id) =0;
		virtual DT::User GetByName(const std::string& login)=0;
	
	};
}
