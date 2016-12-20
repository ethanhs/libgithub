#pragma once

#ifndef GITHUB_HPP
#define GITHUB_HPP


#include "user.hpp"
#include "repo.hpp"


namespace Github {


	class Github {
	public:
		void login(std::string username, std::string password);
		void login(std::string access_token);
		void login();
	};

	void Github::login(std::string username, std::string password) {
		GithubUtil::login(username, password);
	}

	void Github::login(std::string access_token) {
		GithubUtil::login(access_token);
	}

	void Github::login() {

	}

}

#endif // GITHUB_HPP

