#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	int i, j, money, food;
	bool has_key;

	Player();
	Player(int i, int j, int money, int food);
	void change_money(int amount);
	void change_food(int amount);
};

#endif