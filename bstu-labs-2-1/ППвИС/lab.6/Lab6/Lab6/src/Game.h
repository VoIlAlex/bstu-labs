#ifndef _GAME_H_
#define _GAME_H_
#include <iostream>
#include <string>
#define UnitHealth double
#define UnitMana double
#define UnitDamage double
#define UnitName std::string
enum UnitState
{
	UNIT_DEAD = 0,
	UNIT_ALIVE
};
namespace Game
{
	class Unit
	{
	protected:
		UnitName name;
		UnitHealth health;
		UnitMana mana;
		UnitDamage damage;
		UnitState state;
	public:
		Unit();
		Unit(UnitName n, UnitHealth h, UnitMana m, UnitDamage d);
		void attack(Unit& victim) const;
		UnitState isAlive() const;
	};
} // namespace Game
#endif