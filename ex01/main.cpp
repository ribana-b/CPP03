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

int	main()
{
	myTest();
	return (0);
}
