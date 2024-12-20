/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:57:01 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/12/20 14:02:23 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <iostream>
# include <stdio.h>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &that);
		DiamondTrap(const std::string &name);

		const std::string	&getName() const;
		void				setName(const std::string &name);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		DiamondTrap	&operator=(const DiamondTrap &that);

		void	guardGate();
		void	highFivesGuys(void);
		void	whoAmI();

	private:
		std::string	name;
};

#endif // DIAMONDTRAP_HPP
