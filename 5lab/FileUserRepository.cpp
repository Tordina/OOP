#include "FileUserRepository.h"
#include <iostream>
#include <fstream>

namespace AS
{
	FileUserRepository::FileUserRepository()
	{
		users.clear();
		std::ifstream in("users.txt");

		if (in.is_open())
		{
			AS::User user;

			while (in >> user.id >> user.login >> user.password >> user.name)
			{
				users.push_back(user);
			}
		}

		in.close();
	}

	AS::User FileUserRepository::GetById(int id)
	{
		AS::User user;

		for (const AS::User& userF : users)
		{
			if (userF.id == id)
			{
				user = userF;
				break;
			}
		}
		return user;
	}

	AS::User FileUserRepository::GetByName(const std::string& login)
	{
		AS::User user;

		for (const AS::User& userF : users)
		{
			if (userF.login == login)
			{
				user = userF;
				return user;
			}
		}
		return user;
	}

	std::vector<AS::User> FileUserRepository::Get() const { return users; }

	void FileUserRepository::Add(AS::User user)
	{
		users.push_back(user);
		saveToFile();
	}

	void FileUserRepository::Remove(AS::User user)
	{
		auto del = users.begin();

		while (del != users.end())
		{
			if (del->id == user.id)
			{
				users.erase(del);
				break;
			}
			else
			{
				++del;
			}
		}
		saveToFile();
	}

	AS::User FileUserRepository::checkLogin()
	{
		std::ifstream in("Authorization.txt");
		AS::User user;

		if (in.is_open())
		{
			in >> user.id >> user.login >> user.password >> user.name;
			in.close();
		}
		return user;
	}

	void FileUserRepository::saveToFile()
	{
		std::ofstream out("users.txt");

		if (out.is_open())
		{
			for (auto const& user : users)
			{
				out << user.id << " " << user.login << " " << user.password << " " << user.name;
			}
		}
		out.close();
	}

	int FileUserRepository::createNewId()
	{
		return users.size() + 1;
	}
}

