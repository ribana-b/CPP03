#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap dt("Foo");
	std::cout << dt.getAttackDamage() << std::endl;
	std::cout << dt.getEnergyPoints() << std::endl;
	dt.highFivesGuys();
	dt.attack("foo");
	dt.guardGate();
	dt.whoAmI();
	return (0);
}
