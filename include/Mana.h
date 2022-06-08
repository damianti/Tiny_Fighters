#pragma once

class Mana
{
public:
	Mana();
	void addMana(const int add);
	void useMana(const int used);
private:
	int m_mana;
};