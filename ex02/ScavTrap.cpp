/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:42:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/12/18 00:33:15 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	isGuardMode = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	isGuardMode = false;
	std::cout << "ScavTrap String Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &that) : ClapTrap(that.getName())
{
	hitPoints = that.getHitPoints();
	energyPoints = that.getEnergyPoints();
	attackDamage = that.getAttackDamage();
	isGuardMode = that.getIsGuardMode();
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &that)
{
	if (this != &that)
	{
		name = that.getName();
		hitPoints = that.getHitPoints();
		energyPoints = that.getEnergyPoints();
		attackDamage = that.getAttackDamage();
		isGuardMode = that.getIsGuardMode();
	}
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

bool	ScavTrap::getIsGuardMode() const
{
	return (isGuardMode);
}

void	ScavTrap::setIsGuardMode(bool isGuardMode)
{
	this->isGuardMode = isGuardMode;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because is dead" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because is exhausted" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < 0)
	{
		std::cout << "ScavTrap " << name << " can't take damage because is dead" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " receives " << amount << " damage" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " has fainted" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPoints < 0)
	{
		std::cout << "ScavTrap " << name << " can't be repaired because is dead" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't be repaired because is exhausted" << std::endl;
		return;
	}
	if (hitPoints == 10)
	{
		std::cout << "ScavTrap " << name << " can't be repaired because has max hitPoints" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " recovered " << amount << " hitPoints" << std::endl;
	--energyPoints;
	hitPoints += amount;
	if (hitPoints > 100)
		hitPoints = 100;
}

void	ScavTrap::guardGate()
{
	if (hitPoints < 0)
	{
		std::cout << "ScavTrap " << name << " can't guard because is dead" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't guard because is exhausted" << std::endl;
		return;
	}
	if (isGuardMode)
	{
		std::cout << "ScavTrap is already in Gatekeeper mode" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode" << std::endl;
	isGuardMode = true;
}
