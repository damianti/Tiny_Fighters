#pragma once

class Health
{
public:
	Health();
	void addHealth(const int add);
	void useHealth(const int used);
private:
	int m_health;
};