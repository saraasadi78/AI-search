#include "Node.h"
#include "Loot.h"
#include "Bridge.h"
#include "Bandit.h"
#include "Wild_Animal.h"

Node::Node() {}

Node::Node(Map map, Player player, int parent_index, string action)
{
	this->map = map.Copy();
	this->player = player;
	this->parent_index = parent_index;
	this->action = action;

}

vector<Node> Node::Successor(int index)
{
	vector<Node> result;

	if (this->player.j < this->map.cols - 1) //player can go right
	{
		Base_Entity *entity = this->map.at(player.i, player.j + 1);
		if (entity->name != 'S')
		{
			if (entity->name == 'G')
			{
				Node temp(map, player, index, "right");
				temp.player.j++;
				result.push_back(temp);
			}
			else if (entity->name == 'P')
			{
				if (((Bridge *)entity)->traversed == false)
				{
					Node temp(map, player, index, "right");
					temp.player.j++;
					((Bridge *)temp.map.at(temp.player.i, temp.player.j))->traversed = true;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'C')
			{
				if (player.has_key)
				{
					Node temp(map, player, index, "right");
					temp.player.j++;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'K')
			{
				Node temp(map, player, index, "right");
				temp.player.j++;
				temp.player.has_key = true;
				result.push_back(temp);
			}
			else if (entity->name == 'B')
			{
				Bandit *bandit = (Bandit *)entity;
				if (player.money > bandit->power)
				{
					Node temp(map, player, index, "right");
					temp.player.j++;
					bandit->Take_Money(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'W')
			{
				Wild_Animal *wild_animal = (Wild_Animal *)entity;
				if (player.food > wild_animal->power)
				{
					Node temp(map, player, index, "right");
					temp.player.j++;
					wild_animal->Take_Food(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'L')
			{
				Loot *loot = (Loot *)entity;
				if (loot->used)
				{
					Node temp(map, player, index, "right");
					temp.player.j++;
					result.push_back(temp);
				}
				else
				{
					Node temp1(map, player, index, "right, use money");
					temp1.player.j++;
					((Loot *)temp1.map.at(temp1.player.i, temp1.player.j))->Use_Money(temp1.player);

					Node temp2(map, player, index, "right, use food");
					temp2.player.j++;
					((Loot *)temp2.map.at(temp2.player.i, temp2.player.j))->Use_Food(temp2.player);

					result.push_back(temp1);
					result.push_back(temp2);
				}
			}
		}
	}

	if (this->player.j > 0) //player can go left
	{
		Base_Entity *entity = this->map.at(player.i, player.j - 1);
		if (entity->name != 'S')
		{
			if (entity->name == 'G')
			{
				Node temp(map, player, index, "left");
				temp.player.j--;
				result.push_back(temp);
			}
			else if (entity->name == 'P')
			{
				if (((Bridge *)entity)->traversed == false)
				{
					Node temp(map, player, index, "left");
					temp.player.j--;
					((Bridge *)temp.map.at(temp.player.i, temp.player.j))->traversed = true;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'C')
			{
				if (player.has_key)
				{
					Node temp(map, player, index, "left");
					temp.player.j--;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'K')
			{
				Node temp(map, player, index, "left");
				temp.player.j--;
				temp.player.has_key = true;
				result.push_back(temp);
			}
			else if (entity->name == 'B')
			{
				Bandit *bandit = (Bandit *)entity;
				if (player.money > bandit->power)
				{
					Node temp(map, player, index, "left");
					temp.player.j--;
					bandit->Take_Money(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'W')
			{
				Wild_Animal *wild_animal = (Wild_Animal *)entity;
				if (player.food > wild_animal->power)
				{
					Node temp(map, player, index, "left");
					temp.player.j--;
					wild_animal->Take_Food(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'L')
			{
				Loot *loot = (Loot *)entity;
				if (loot->used)
				{
					Node temp(map, player, index, "left");
					temp.player.j--;
					result.push_back(temp);
				}
				else
				{
					Node temp1(map, player, index, "left, use money");
					temp1.player.j--;
					((Loot *)temp1.map.at(temp1.player.i, temp1.player.j))->Use_Money(temp1.player);

					Node temp2(map, player, index, "left, use food");
					temp2.player.j--;
					((Loot *)temp2.map.at(temp2.player.i, temp2.player.j))->Use_Food(temp2.player);

					result.push_back(temp1);
					result.push_back(temp2);
				}
			}
		}
	}

	if (this->player.i > 0) //player can go up
	{
		Base_Entity *entity = this->map.at(player.i - 1, player.j);
		if (entity->name != 'S')
		{
			if (entity->name == 'G')
			{
				Node temp(map, player, index, "up");
				temp.player.i--;
				result.push_back(temp);
			}
			else if (entity->name == 'P')
			{
				if (((Bridge *)entity)->traversed == false)
				{
					Node temp(map, player, index, "up");
					temp.player.i--;
					((Bridge *)temp.map.at(temp.player.i, temp.player.j))->traversed = true;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'C')
			{
				if (player.has_key)
				{
					Node temp(map, player, index, "up");
					temp.player.i--;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'K')
			{
				Node temp(map, player, index, "up");
				temp.player.i--;
				temp.player.has_key = true;
				result.push_back(temp);
			}
			else if (entity->name == 'B')
			{
				Bandit *bandit = (Bandit *)entity;
				if (player.money > bandit->power)
				{
					Node temp(map, player, index, "up");
					temp.player.i--;
					bandit->Take_Money(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'W')
			{
				Wild_Animal *wild_animal = (Wild_Animal *)entity;
				if (player.food > wild_animal->power)
				{
					Node temp(map, player, index, "up");
					temp.player.i--;
					wild_animal->Take_Food(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'L')
			{
				Loot *loot = (Loot *)entity;
				if (loot->used)
				{
					Node temp(map, player, index, "up");
					temp.player.i--;
					result.push_back(temp);
				}
				else
				{
					Node temp1(map, player, index, "up, use money");
					temp1.player.i--;
					((Loot *)temp1.map.at(temp1.player.i, temp1.player.j))->Use_Money(temp1.player);

					Node temp2(map, player, index, "up, use food");
					temp2.player.i--;
					((Loot *)temp2.map.at(temp2.player.i, temp2.player.j))->Use_Food(temp2.player);

					result.push_back(temp1);
					result.push_back(temp2);
				}
			}
		}
	}

	if (this->player.i < this->map.rows - 1) //player can go down
	{
		Base_Entity *entity = this->map.at(player.i + 1, player.j);
		if (entity->name != 'S')
		{
			if (entity->name == 'G')
			{
				Node temp(map, player, index, "down");
				temp.player.i++;
				result.push_back(temp);
			}
			else if (entity->name == 'P')
			{
				if (((Bridge *)entity)->traversed == false)
				{
					Node temp(map, player, index, "down");
					temp.player.i++;
					((Bridge *)temp.map.at(temp.player.i, temp.player.j))->traversed = true;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'C')
			{
				if (player.has_key)
				{
					Node temp(map, player, index, "down");
					temp.player.i++;
					result.push_back(temp);
				}
			}
			else if (entity->name == 'K')
			{
				Node temp(map, player, index, "down");
				temp.player.i++;
				temp.player.has_key = true;
				result.push_back(temp);
			}
			else if (entity->name == 'B')
			{
				Bandit *bandit = (Bandit *)entity;
				if (player.money > bandit->power)
				{
					Node temp(map, player, index, "down");
					temp.player.i++;
					bandit->Take_Money(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'W')
			{
				Wild_Animal *wild_animal = (Wild_Animal *)entity;
				if (player.food > wild_animal->power)
				{
					Node temp(map, player, index, "down");
					temp.player.i++;
					wild_animal->Take_Food(temp.player);
					result.push_back(temp);
				}
			}
			else if (entity->name == 'L')
			{
				Loot *loot = (Loot *)entity;
				if (loot->used)
				{
					Node temp(map, player, index, "down");
					temp.player.i++;
					result.push_back(temp);
				}
				else
				{
					Node temp1(map, player, index, "down, use money");
					temp1.player.i++;
					((Loot *)temp1.map.at(temp1.player.i, temp1.player.j))->Use_Money(temp1.player);

					Node temp2(map, player, index, "down, use food");
					temp2.player.i++;
					((Loot *)temp2.map.at(temp2.player.i, temp2.player.j))->Use_Food(temp2.player);

					result.push_back(temp1);
					result.push_back(temp2);
				}
			}
		}
	}

	return result;
}

string Node::Hash()
{
	string result;
	result += to_string(player.i) + ",";
	result += to_string(player.j) + ",";
	result += to_string(player.money) + ",";
	result += to_string(player.food) + ",";
	result += to_string(player.has_key);

	for (int i = 0; i < map.game.size(); i++)
	{
		if (map.game[i]->name == 'L')
		{
			Loot* loot = (Loot*)map.game[i];
			result += to_string(loot->used);
		}
		else if (map.game[i]->name == 'P')
		{
			Bridge* bridge = (Bridge*)map.game[i];
			result += to_string(bridge->traversed);
		}
	}

	return result;
}