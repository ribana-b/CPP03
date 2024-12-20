#include "DiamondTrap.hpp"

void	myTest(void)
{
	DiamondTrap dt("Yes");

	std::cout << "Diamond Name: " << dt.getName() << std::endl;
	std::cout << "Diamond Hit Points: " << dt.getHitPoints() << std::endl;
	std::cout << "Diamond Attack Damage: " << dt.getAttackDamage() << std::endl;
	std::cout << "Diamond Energy Points: " << dt.getEnergyPoints() << std::endl;

	dt.highFivesGuys();
	dt.guardGate();
	dt.whoAmI();
}

void	myTest2(void)
{
	DiamondTrap dt;

	std::cout << "Diamond Name: " << dt.getName() << std::endl;
	std::cout << "Diamond Hit Points: " << dt.getHitPoints() << std::endl;
	std::cout << "Diamond Attack Damage: " << dt.getAttackDamage() << std::endl;
	std::cout << "Diamond Energy Points: " << dt.getEnergyPoints() << std::endl;

	dt.highFivesGuys();
	dt.guardGate();
	dt.whoAmI();
}

void	myTest3(void)
{
	DiamondTrap dt;
	DiamondTrap dt2("No");

	dt = dt2;
	std::cout << "Diamond Name: " << dt.getName() << std::endl;
	std::cout << "Diamond Hit Points: " << dt.getHitPoints() << std::endl;
	std::cout << "Diamond Attack Damage: " << dt.getAttackDamage() << std::endl;
	std::cout << "Diamond Energy Points: " << dt.getEnergyPoints() << std::endl;

	dt.highFivesGuys();
	dt.guardGate();
	dt.whoAmI();
}

int	main()
{
	myTest();
	myTest2();
	myTest3();
	return (0);
}
