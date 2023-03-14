#include "Harl.hpp"

void	Harl::debug(){
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"<<std::endl;
}

void	Harl::info(){
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void	Harl::warning(){
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month."<<std::endl;
}

void	Harl::error(){
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;

}

void	Harl::complain(std::string level){
		int i;
		std::string msg[4] = {"debug", "info", "warning", "error"};

		void (Harl::*ptr[4])(void);
		ptr[0] = &Harl::debug;
		ptr[1] = &Harl::info;
		ptr[2] = &Harl::warning;
		ptr[3] = &Harl::error;
		for(i = 0; i < 4; i++){
			if (!msg[i].find(level)) break;
		}
		std::cout << i << std::endl;
		(this->*ptr[i])();
}