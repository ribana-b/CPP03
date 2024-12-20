#include "ClapTrap.hpp"

void	myTest(void)
{
	ClapTrap	ct;

	for (int i = 0; i < 100 && ct.getHitPoints() > 0 && ct.getEnergyPoints() > 0; ++i)
	{
		ct.attack("foo");
		ct.beRepaired(10);
	}
	ct.attack("foo");
	ct.beRepaired(10);
}

void	myTest2(void)
{
	ClapTrap	ct("foo");

	for (int i = 0; i < 100 && ct.getHitPoints() > 0 && ct.getEnergyPoints() > 0; ++i)
	{
		ct.attack("bar");
		if (i % 2 == 0)
			ct.takeDamage(11);
		ct.beRepaired(10);
	}
	ct.attack("bar");
	ct.beRepaired(10);
}

void	myTest3(void)
{
	ClapTrap	ct;
	ClapTrap	ct2("bar");

	ct = ct2;
	for (int i = 0; i < 100 && ct.getHitPoints() > 0 && ct.getEnergyPoints() > 0; ++i)
	{
		ct.attack("bar");
		if (i % 2 == 0)
			ct.takeDamage(4);
		ct.beRepaired(3);
	}
	ct.attack("bar");
	ct.beRepaired(10);
}

int	main()
{
	myTest();
	myTest2();
	myTest3();
	return (0);
}
