/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:36:47 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/12/20 02:07:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap String Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &that) : ClapTrap(that.getName())
{
	hitPoints = that.getHitPoints();
	energyPoints = that.getEnergyPoints();
	attackDamage = that.getAttackDamage();
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &that)
{
	if (this != &that)
	{
		name = that.getName();
		hitPoints = that.getHitPoints();
		energyPoints = that.getEnergyPoints();
		attackDamage = that.getAttackDamage();
	}
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (!hitPoints)
	{
		std::cout << "FragTrap " << name << " can't attack because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "FragTrap " << name << " can't attack because is exhausted" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "FragTrap " << name << " can't take damage because is dead" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " receives " << amount << " damage" << std::endl;
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	if (!hitPoints)
		std::cout << "FragTrap " << name << " has fainted" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (!hitPoints)
	{
		std::cout << "FragTrap " << name << " can't be repaired because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "FragTrap " << name << " can't be repaired because is exhausted" << std::endl;
		return;
	}
	if (hitPoints == 100)
	{
		std::cout << "FragTrap " << name << " can't be repaired because has max hitPoints" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " recovered " << amount << " hitPoints" << std::endl;
	--energyPoints;
	hitPoints += amount;
	if (hitPoints > 100)
		hitPoints = 100;
}

void	FragTrap::highFivesGuys(void)
{
	if (!hitPoints)
	{
		std::cout << "FragTrap " << name << " can't be repaired because is dead" << std::endl;
		return;
	}
	if (!energyPoints)
	{
		std::cout << "FragTrap " << name << " can't request high fives because is exhausted" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " is requesting a highFivesGuys" << std::endl;
}
