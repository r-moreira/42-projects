#ifndef FT_CONTAINERS_CLAPTRAP_H
#define FT_CONTAINERS_CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();

    ClapTrap(std::string _name);

    ClapTrap(const ClapTrap &ct);

    virtual ~ClapTrap();

    virtual void attack(std::string const &target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    ClapTrap &operator=(const ClapTrap &ct);

    void setName(std::string name);

    void setHitPoints(unsigned int amount);

    void setEnergyPoints(unsigned int amount);

    void setAttackDamage(unsigned int amount);

    std::string getName() const;

    unsigned int getHitPoints() const;

    unsigned int getEnergyPoints() const;

    unsigned int getAttackDamage() const;
};


#endif //FT_CONTAINERS_CLAPTRAP_H
