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

int	main()
{
	myTest();
	return (0);
}
