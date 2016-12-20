#pragma once
#ifndef REQUESTS_HPP
#define REQUESTS_HPP

#include <cpr/cpr.h>



namespace GithubUtil {



	const std::string api_url = "https://api.github.com";
	std::array<std::string, 2> credentials = { {"",""} };
	std::string access_token = "";
	bool use_cred = true;

	void login(std::string username, std::string password) {
		use_cred = true;
		credentials = { { username, password } };
	}

	void login(std::string token) {
		use_cred = false;
		access_token = token;
	}

	std::string make_get_request(std::string url) {
		cpr::Session gh_session;
		gh_session.SetUrl(cpr::Url{ api_url+url });
		if (use_cred && credentials[0] != "" && credentials[1] != "") {
			gh_session.SetAuth(cpr::Authentication{ credentials[0], credentials[1] });
			gh_session.SetHeader(cpr::Header{ { "Accept", "application/json" } });
		}
		else if (access_token != "") {
			gh_session.SetHeader(cpr::Header{ { "Authorization", "token " + access_token },{ "Accept", "application/json" } });
		}
		else
		{
			gh_session.SetHeader(cpr::Header{ { "Accept", "application/json" } });
		}
		auto ret = gh_session.Get();
		if (ret.status_code == 200) {
			return ret.text;
		}
		else {
			throw "Request failed with status code " + std::to_string(ret.status_code) + "\n" +
				"The returned text was:\n" + ret.text;
		}
		
	}

}



#endif // REQUESTS_HPP
