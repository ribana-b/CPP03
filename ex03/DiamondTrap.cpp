/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 01:03:03 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/12/20 02:33:06 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap(),
	FragTrap(),
	ScavTrap(),
	name("Default")
{
	ClapTrap::name += "_clap_name";
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	name(name)
{
	std::cout << "DiamondTrap String Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &that) :
	ClapTrap(that.getName() + "_clap_name"),
	FragTrap(that.getName()),
	ScavTrap(that.getName())
{
	hitPoints = that.getHitPoints();
	energyPoints = that.getEnergyPoints();
	attackDamage = that.getAttackDamage();
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &that)
{
	if (this != &that)
	{
		name = that.getName();
		hitPoints = that.getHitPoints();
		energyPoints = that.getEnergyPoints();
		attackDamage = that.getAttackDamage();
	}
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	&DiamondTrap::getName(void) const
{
	return (name);
}

void	DiamondTrap::setName(const std::string &newName)
{
	name = newName;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	if (!hitPoints)
	{
		std::cout << "DiamondTrap " << name << " can't attack because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "DiamondTrap " << name << " can't attack because is exhausted" << std::endl;
		return;
	}
	std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "DiamondTrap " << name << " can't take damage because is dead" << std::endl;
		return;
	}
	std::cout << "DiamondTrap " << name << " receives " << amount << " damage" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	if (!hitPoints)
		std::cout << "DiamondTrap " << name << " has fainted" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "DiamondTrap " << name << " can't be repaired because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "DiamondTrap " << name << " can't be repaired because is exhausted" << std::endl;
		return;
	}
	if (hitPoints == 100)
	{
		std::cout << "DiamondTrap " << name << " can't be repaired because has max hitPoints" << std::endl;
		return;
	}
	std::cout << "DiamondTrap " << name << " recovered " << amount << " hitPoints" << std::endl;
	--energyPoints;
	hitPoints += amount;
	if (hitPoints > 100)
		hitPoints = 100;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
