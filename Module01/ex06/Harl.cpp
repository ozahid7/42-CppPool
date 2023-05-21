#include "Harl.hpp"

void	Harl::myerror(){
	std::cerr<<"[ Probably complaining about insignificant problems ]"<<std::endl;
}

void	Harl::debug(){
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"<<std::endl;
}

void	Harl::info(){
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n"<<std::endl;
}

void	Harl::warning(){
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming foryears whereas you started working here since last month.\n"<<std::endl;
}

void	Harl::error(){
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now.\n"<<std::endl;

}

void	Harl::complain(std::string level){
		int i;
		std::string msg[5] = {"DEBUG", "INFO", "WARNING", "ERROR"};

		void (Harl::*ptr[4])(void);
		ptr[0] = &Harl::debug;
		ptr[1] = &Harl::info;
		ptr[2] = &Harl::warning;
		ptr[3] = &Harl::error;
		for (i = 0; i < 4; i++){
			if (!msg[i].find(level) && !level.empty()) break;
		}
		switch (i){
			case 0:
					(this->*ptr[i++])();
			case 1:
					(this->*ptr[i++])();
			case 2:
					(this->*ptr[i++])();
			case 3:
					(this->*ptr[i++])();
				break;
			default:
				myerror();
		}
}