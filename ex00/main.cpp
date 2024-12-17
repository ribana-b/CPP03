#include "ClapTrap.hpp"

int	main()
{
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
	{
		ClapTrap	ct("foo");

		for (int i = 0; i < 100 && ct.getHitPoints() > 0 && ct.getEnergyPoints() > 0; ++i)
		{
			ct.attack("bar");
			ct.beRepaired(10);
		}
		ct.attack("bar");
		ct.beRepaired(10);
	}
	return (0);
}
