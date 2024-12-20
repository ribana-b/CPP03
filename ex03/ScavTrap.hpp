/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:40:17 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/12/20 14:04:57 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

/* @------------------------------------------------------------------------@ */
/* |                            Include Section                             | */
/* @------------------------------------------------------------------------@ */

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

/* @------------------------------------------------------------------------@ */
/* |                             Class Section                              | */
/* @------------------------------------------------------------------------@ */

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &that);
		ScavTrap(const std::string &name);

		bool	getIsGuardMode(void) const;
		void	setIsGuardMode(bool isGuardMode);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate();

		ScavTrap	&operator=(const ScavTrap &that);

	protected:
		bool	isGuardMode;
};

#endif // SCAVTRAP_HPP
