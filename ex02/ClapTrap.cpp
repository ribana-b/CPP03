/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:26:32 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/12/20 02:03:41 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("Default"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &that) :
	name(that.name),
	hitPoints(that.hitPoints),
	energyPoints(that.energyPoints),
	attackDamage(that.attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) :
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0)
{
	std::cout << "ClapTrap String constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &that)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &that)
	{
		name = that.name;
		hitPoints = that.hitPoints;
		energyPoints = that.energyPoints;
		attackDamage = that.attackDamage;
	}
	return (*this);
}

const std::string	&ClapTrap::getName(void) const
{
	return (name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (hitPoints);
}


int	ClapTrap::getEnergyPoints(void) const
{
	return (energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (attackDamage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!hitPoints)
	{
		std::cout << "ClapTrap " << name << " can't attack because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "ClapTrap " << name << " can't attack because is exhausted" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "ClapTrap " << name << " can't take damage because is dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " receives " << amount << " damage" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	if (!hitPoints)
		std::cout << "ClapTrap " << name << " has fainted" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "ClapTrap " << name << " can't be repaired because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "ClapTrap " << name << " can't be repaired because is exhausted" << std::endl;
		return;
	}
	if (hitPoints == 10)
	{
		std::cout << "ClapTrap " << name << " can't be repaired because has max hitPoints" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " recovered " << amount << " hitPoints" << std::endl;
	--energyPoints;
	hitPoints += amount;
	if (hitPoints > 10)
		hitPoints = 10;
}
