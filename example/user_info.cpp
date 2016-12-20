#include "github.hpp"
#include <iostream>


int main(int argc, char** argv) {
	auto g = Github::Github();
	g.login();
	auto u = Github::User("ethanhs");
	std::cout << u.name() << std::endl;
	std::cout << u.nick() << std::endl;
	std::cout << u.company() << std::endl;
	std::cout << u.url() << std::endl;
	std::cout << u.location() << std::endl;
	std::cout << u.bio() << std::endl;
	std::cout << u.blog() << std::endl;
	std::cout << u.id() << std::endl;
	std::cout << u.num_followers() << std::endl;
	std::cout << u.num_following() << std::endl;
	std::cin.get();
	return 0;
}