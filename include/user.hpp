#pragma once
#ifndef USER_HPP
#define USER_HPP

#include <json.hpp>
#include <string>
#include "requests.hpp"


namespace Github {

	class User {
	public:
		User(std::string user_name);
		User(nlohmann::json user);
		std::string nick();
		std::string name();
		std::string avatar_url();
		std::string url();
		std::string company();
		std::string location();
		std::string blog();
		std::string bio();
		int id();
		int num_followers();
		int num_following();
	private:
		nlohmann::json m_json = nullptr;
	};

	User::User(std::string user_name) {
		
		auto ret = GithubUtil::make_get_request("/users/" + user_name);
		nlohmann::json j;
		this->m_json = j.parse(ret);
		
	}
	User::User(nlohmann::json user) {
		this->m_json = user;
	}

	std::string User::nick() {
		if (this->m_json != nullptr && !this->m_json["login"].is_null()) {
			return this->m_json["login"];
		}
		else {
			return "";
		}
	}

	std::string User::name() {
		if (this->m_json != nullptr && !this->m_json["name"].is_null()) {
			return this->m_json["name"];
		}
		else {
			return "";
		}
	}

	std::string User::avatar_url() {
		if (this->m_json != nullptr && !this->m_json["avatar_url"].is_null()) {
			return this->m_json["avatar_url"];
		}
		else {
			return "";
		}
	}

	std::string User::url() {
		if (this->m_json != nullptr && !this->m_json["url"].is_null()) {
			return this->m_json["url"];
		}
		else {
			return "";
		}
	}

	std::string User::company() {
		if (this->m_json != nullptr && !this->m_json["company"].is_null()) {
			return this->m_json["company"];
		}
		else {
			return "";
		}
	}

	std::string User::location() {
		if (this->m_json != nullptr && !this->m_json["location"].is_null()) {
			return this->m_json["location"];
		}
		else {
			return "";
		}
	}

	std::string User::blog() {
		if (this->m_json != nullptr && !this->m_json["blog"].is_null()) {
			return this->m_json["blog"];
		}
		else {
			return "";
		}
	}

	std::string User::bio() {
		if (this->m_json != nullptr && !this->m_json["bio"].is_null()) {
			return this->m_json["bio"];
		}
		else {
			return "";
		}
	}

	int User::id() {
		if (this->m_json != nullptr && !this->m_json["id"].is_null()) {
			return this->m_json["id"];
		}
		else {
			return -1;
		}
	}

	int User::num_followers() {
		if (this->m_json != nullptr && !this->m_json["followers"].is_null()) {
			return this->m_json["followers"];
		}
		else {
			return -1;
		}
	}

	int User::num_following() {
		if (this->m_json != nullptr && !this->m_json["following"].is_null()) {
			return this->m_json["following"];
		}
		else {
			return -1;
		}
	}


}

#endif // USER_HPP
