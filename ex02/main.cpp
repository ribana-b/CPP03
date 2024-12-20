#include "FragTrap.hpp"

void	myTest(void)
{
	FragTrap	ft;

	ft.highFivesGuys();
	for (int i = 0; i < 100 && ft.getHitPoints() > 0 && ft.getEnergyPoints() > 0; ++i)
	{
		ft.attack("foo");
		ft.beRepaired(10);
	}
	ft.highFivesGuys();
	ft.attack("foo");
	ft.beRepaired(10);
}

void	myTest2(void)
{
	FragTrap	ft("_mytest2");

	ft.highFivesGuys();
	for (int i = 0; i < 10 && ft.getHitPoints() > 0 && ft.getEnergyPoints() > 0; ++i)
	{
		ft.attack("lol");
		ft.takeDamage(11);
		ft.beRepaired(10);
	}
	ft.highFivesGuys();
	ft.attack("lol");
	ft.beRepaired(10);
}

void	myTest3(void)
{
	FragTrap	ft("_mytest3");

	ft.highFivesGuys();
	for (int i = 0; i < 100 && ft.getHitPoints() > 0 && ft.getEnergyPoints() > 0; ++i)
	{
		ft.attack("lol");
		ft.takeDamage(11);
		ft.beRepaired(10);
	}
	ft.highFivesGuys();
	ft.attack("lol");
	ft.beRepaired(10);
}

void	myTest4(void)
{
	FragTrap	ft;
	FragTrap	ft2("_mytest4");

	ft = ft2;
	ft.highFivesGuys();
	for (int i = 0; i < 100 && ft.getHitPoints() > 0 && ft.getEnergyPoints() > 0; ++i)
	{
		ft.attack("lol");
		ft.takeDamage(11);
		ft.beRepaired(10);
	}
	ft.highFivesGuys();
	ft.attack("lol");
	ft.beRepaired(10);
}

int	main()
{
	myTest();
	myTest2();
	myTest3();
	myTest4();
	return (0);
}
