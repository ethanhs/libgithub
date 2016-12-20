#pragma once
#ifndef REPO_HPP
#define REPO_HPP

#include <string>
#include <vector>
#include <json.hpp>
#include "requests.hpp"

namespace Github {
	
	class Repo {
	public:
		Repo(std::string repo_path);
		Repo(nlohmann::json repo);
		std::string owner_name();
		std::string name();
		std::string full_name();
		std::string description();
		std::string url();
		std::vector<nlohmann::json> contributors();
		nlohmann::json owner();
		int num_forks();
		int num_stars();

		
	private:
		nlohmann::json m_json = nullptr;
	};

	Repo::Repo(std::string repo_path) {
		auto ret = GithubUtil::make_get_request("/repos/" + repo_path);
		nlohmann::json j;
		this->m_json = j.parse(ret);
	}

	Repo::Repo(nlohmann::json repo) {
		this->m_json = repo;
	}

	std::string Repo::owner_name() {
		if (this->m_json != nullptr && !this->m_json["owner"].is_null()) {
			return this->m_json["owner"]["login"];
		}
		else {
			return "";
		}
	}

	std::string Repo::name() {
		if (this->m_json != nullptr && !this->m_json["name"].is_null()) {
			return this->m_json["name"];
		}
		else {
			return "";
		}
	}

	std::string Repo::full_name() {
		if (this->m_json != nullptr && !this->m_json["full_name"].is_null()) {
			return this->m_json["full_name"];
		}
		else {
			return "";
		}
	}

	std::string Repo::description() {
		if (this->m_json != nullptr && !this->m_json["description"].is_null()) {
			return this->m_json["description"];
		}
		else {
			return "";
		}
	}

	std::string Repo::url() {
		if (this->m_json != nullptr && !this->m_json["html_url"].is_null()) {
			return this->m_json["html_url"];
		}
		else {
			return "";
		}
	}

	int Repo::num_stars() {
		if (this->m_json != nullptr && !this->m_json["stargazers_count"].is_null()) {
			return this->m_json["stargazers_count"];
		}
		else {
			return -1;
		}
	}

	int Repo::num_forks() {
		if (this->m_json != nullptr && !this->m_json["forks_count"].is_null()) {
			return this->m_json["forks_count"];
		}
		else {
			return -1;
		}
	}

	std::vector<nlohmann::json> Repo::contributors() {
		auto ret = GithubUtil::make_get_request("/repos/" + this->full_name());
		nlohmann::json j;
		return j.parse(ret);
	}

	nlohmann::json Repo::owner() {
		if (this->m_json != nullptr && !this->m_json["owner"].is_null()) {
			return this->m_json["owner"];
		}
		else {
			return "";
		}
	}
}

#endif // REPO_HPP
