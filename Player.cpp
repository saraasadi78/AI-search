#include "Player.h"

Player::Player() {}

Player::Player(int i, int j, int money, int food)
{
	this->i = i;
	this->j = j;
	this->money = money;
	this->food = food;
	this->has_key = false;
}

void Player::change_money(int amount)
{
	money += amount; //amount can be negative
}

void Player::change_food(int amount)
{
	food += amount; //amount can be negative
}