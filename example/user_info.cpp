#include "github.hpp"
#include <iostream>


int main(int argc, char** argv) {
	auto g = Github::Github();
	// we don't need to pass any authenification for testing
	g.login();
	// Github::User test
	std::string username = "ethanhs";
	auto u = Github::User(username);
	std::cout << "Testing User class:" << std::endl;
	std::cout << "Name: ";
	std::cout << u.name() << std::endl;
	std::cout << "Login: ";
	std::cout << u.nick() << std::endl;
	std::cout << "Company: ";
	std::cout << u.company() << std::endl;
	std::cout << "URL: ";
	std::cout << u.url() << std::endl;
	std::cout << "Location: ";
	std::cout << u.location() << std::endl;
	std::cout << "Bio: ";
	std::cout << u.bio() << std::endl;
	std::cout << "Blog URL: ";
	std::cout << u.blog() << std::endl;
	std::cout << "UserID: ";
	std::cout << u.id() << std::endl;
	std::cout << "Num followers: ";
	std::cout << u.num_followers() << std::endl;
	std::cout << "Num following: ";
	std::cout << u.num_following() << std::endl;

	std::cout << "\n" << std::endl;

	// Github::Repo test
	std::string repo = "ethanhs/WSL-Programs";
	auto r = Github::Repo(repo);
	std::cout << "Testing Repo class:" << std::endl;
	std::cout << "Full Name: ";
	std::cout << r.full_name() << std::endl;
	std::cout << "Name: ";
	std::cout << r.name() << std::endl;
	std::cout << "Owner's Name: ";
	std::cout << r.owner_name() << std::endl;
	std::cout << "Description: ";
	std::cout << r.description() << std::endl;
	std::cout << "URL: ";
	std::cout << r.url() << std::endl;
	std::cout << "Number of Stars: ";
	std::cout << r.num_stars() << std::endl;
	std::cout << "Number of Forks: ";
	std::cout << r.num_forks() << std::endl;
	std::cin.get();
	return 0;
}