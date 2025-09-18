#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

//Class
class	Zombie
{
public:
    Zombie();
	Zombie(std::string name);
	~Zombie();
    void    setName(std::string name);
	void	announce(void);
private:
	std::string _name;

};

//non member/class functions
Zombie  *zombieHorde(int N, std::string name);
#endif
