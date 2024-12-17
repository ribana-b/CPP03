#include "ScavTrap.hpp"

int	main()
{
	{
		ScavTrap	st;

		for (int i = 0; i < 100 && st.getHitPoints() > 0 && st.getEnergyPoints() > 0; ++i)
		{
			st.attack("foo");
			st.guardGate();
			st.beRepaired(10);
		}
		st.attack("foo");
		st.beRepaired(10);
	}
	return (0);
}
