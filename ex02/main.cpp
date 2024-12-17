#include "FragTrap.hpp"

int	main()
{
	{
		FragTrap	ft;

		for (int i = 0; i < 100 && ft.getHitPoints() > 0 && ft.getEnergyPoints() > 0; ++i)
		{
			ft.attack("foo");
			ft.highFivesGuys();
			ft.beRepaired(10);
		}
		ft.attack("foo");
		ft.beRepaired(10);
	}
	return (0);
}
