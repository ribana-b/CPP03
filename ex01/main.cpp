#include "ScavTrap.hpp"

void	myTest(void)
{
	ScavTrap	st;

	st.guardGate();
	st.guardGate();
	st.takeDamage(20);
	for (int i = 0; i < 100 && st.getHitPoints() > 0 && st.getEnergyPoints() > 0; ++i)
	{
		st.attack("foo");
		st.beRepaired(i);
	}
	st.guardGate();
	st.attack("foo");
	st.beRepaired(10);
}

void	myTest2(void)
{
	ScavTrap	st;

	st.guardGate();
	st.guardGate();
	st.takeDamage(20);
	for (int i = 0; i < 100 && st.getHitPoints() > 0 && st.getEnergyPoints() > 0; ++i)
	{
		st.attack("foo");
		st.takeDamage(5);
		st.beRepaired(4);
	}
	st.guardGate();
	st.attack("foo");
	st.beRepaired(10);
}

void	myTest3(void)
{
	ScavTrap	st("_patrick");

	st.guardGate();
	st.guardGate();
	st.takeDamage(20);
	for (int i = 0; i < 100 && st.getHitPoints() > 0 && st.getEnergyPoints() > 0; ++i)
	{
		st.attack("foo");
		st.takeDamage(i);
		st.beRepaired(i);
	}
	st.guardGate();
	st.attack("foo");
	st.beRepaired(10);
}

void	myTest4(void)
{
	ScavTrap	st;
	ScavTrap	st2("_peter");

	st.guardGate();
	st = st2;
	st.guardGate();
	st.takeDamage(20);
	for (int i = 0; i < 100 && st.getHitPoints() > 0 && st.getEnergyPoints() > 0; ++i)
	{
		st.attack("foo");
		st.takeDamage(i);
		st.beRepaired(i);
	}
	st.guardGate();
	st.attack("foo");
	st.beRepaired(10);
}

int	main()
{
	myTest();
	myTest2();
	myTest3();
	myTest4();
	return (0);
}
