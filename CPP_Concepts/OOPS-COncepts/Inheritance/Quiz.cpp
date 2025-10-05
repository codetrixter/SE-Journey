/**
Here we try to solve the chapter end quiz and questions.
*/
#include <iostream>
#include <string>
/*****************What will be the output******************** */

/* class Base
{
public:
	Base()
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}
};

class Derived: public Base
{
public:
	Derived()
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}
};

int main()
{
	Derived d;
	Base b;
    /// Output:
    /// Base()
    /// Derived()
    /// Base()
    /// ~Base()
    /// ~Derived()
    /// ~Base()

	return 0;
} */
/*****************What will be the output******************** */
/* class Base
{
private:
	int m_x {};
public:
	Base(int x): m_x{ x }
	{
		std::cout << "Base()\n";
	}
	~Base()
	{
		std::cout << "~Base()\n";
	}

	void print() const { std::cout << "Base: " << m_x << '\n';  }
};

class Derived: public Base
{
public:
	Derived(int y):  Base{ y }
	{
		std::cout << "Derived()\n";
	}
	~Derived()
	{
		std::cout << "~Derived()\n";
	}

	void print() const { std::cout << "Derived: " << m_x << '\n'; }
};

int main()
{
	Derived d{ 5 };
	d.print(); // m_x is private in Base, so not accessible in Derived

	return 0;
} */
/*****************What will be the output******************** */
/***************Write clases********************************* */
/* class Fruit
{
private:
	std::string m_name;
	std::string m_color;

public:
	Fruit(std::string_view name, std::string_view color)
		: m_name{ name }, m_color{ color }
	{
	}

	const std::string& getName() const { return m_name; }
	const std::string& getColor() const { return m_color; }
};

class Apple: public Fruit
{
public:
	Apple( std::string_view color="red", std::string_view name = "apple")
		: Fruit( name, color )
	{
	}
};

class Banana : public Fruit
{
public:
	Banana(std::string_view color="yellow", std::string_view name = "banana")
		: Fruit{ name, color }
	{
	}
};

class GrannySmith : public Apple
{
	public:
	GrannySmith()
	: Apple{ "green", "granny smith apple"}
	{
	}
};

int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
} */
/***************Write clases********************************* */
/*************** GAME**************************************** */
#include <cstdlib>	/// for rand() and srand()
#include "random.h"
#include <string_view>

class Creature
{
	protected:
		std::string m_name{};
		char m_symbol {};
		int m_health {};
		int m_damage {};
		int m_gold {};

	public:
		Creature(std::string_view name, char symbol, int health, int damage, int gold)
		: m_name{name}, m_symbol{symbol}, m_health{health}, m_damage{damage}, m_gold(gold)
		{
		}

		void setName(std::string name)
		{
			m_name = name;
		}
		const std::string& getName() const
		{
			return m_name;
		}

		void setSymbol(char symbol)
		{
			m_symbol = symbol;
		}
		char getSymbol() const
		{
			return m_symbol;
		}

		void setHealth(int health)
		{
			m_health = health;
		}
		int getHealth() const
		{
			return m_health;
		}

		void setDamage(int dam)
		{
			m_damage = dam;
		}
		int getDamage() const
		{
			return m_damage;
		}

		void setGold(int gold)
		{
			m_gold = gold;
		}
		int getGold() const
		{ 
			return m_gold;
		}

		void addGold(int gold)
		{
			setGold(getGold() + gold);
		}

		void reduceHealth(int health)
		{
			setHealth(getHealth() - health);
		}

		bool isDead()
		{
			return m_health <= 0;
		}
};

class Player : public Creature
{
	private:
		int m_level {1};

	public:
		Player(std::string name)
		: Creature{name, '@', 10, 1, 0}
		{
		}

		void setLevel(int level)
		{
			m_level = level;
		}
		int getLevel() const
		{
			return m_level;
		}

		void levelUp()
		{
			++m_level;
			++m_damage;
		}

		bool hasWon()
		{
			return m_level >= 20;
		}
};

class Monster : public Creature
{
	public:
		enum Type
		{
			dragon,
			orc,
			slime,
			max_types
		};

	private:
		static inline Creature m_monsterData[] 
		{
			Creature { "dragon", 'D', 20, 4, 100},
			Creature { "orc", 'o', 4, 2, 25},
			Creature { "slime", 's', 1, 1, 10}
		};

		static_assert(std::size(m_monsterData) == Type::max_types);

	public:
		Monster(Type MONSTERTYPE)
		: Creature { m_monsterData[MONSTERTYPE] }	/// copy constructor is called here
		{
		}

		static Type getRandomMonster()
		{
			int choice = Random::get(0, Type::max_types-1);
			return static_cast<Type>(choice);
		}

	
};

int main()
{
	/// Creature o{ "orc", 'o', 4, 2, 10 };
	/// o.addGold(5);
	/// o.reduceHealth(1);
	/// std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

	/// std::string playername {};
	/// std::cout << "Enter your name: ";
	/// std::cin >> playername;

	///**********************************player class */
	/// Player p1 {playername};
	/// std::cout << "Welcome, " << p1.getName() << "\n" << "you have " << p1.getHealth() << " health and are carrying " << p1.getGold() << " gold.";

	///********************************************** */

	/// for (int i{ 0 }; i < 10; i++)
	/// {
	/// 	Monster m{ Monster::getRandomMonster() };
	/// 	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	/// }
	
	/******************************Actual Turn based game ****************** */

	/// Prompts of the game
	std::string playerName {};
	std:: cout << "Enter your name: ";
	std::cin >> playerName;
	std::cout << "\nWelcome, " << playerName << std::endl;

	Player player {playerName};
	Monster monster{};
	char choose;

	/**********Game loop starts here **************************/

	while(!player.isDead() && !player.hasWon())
	{
		if(!monster.isDead() | !monster.getName().empty())
		{
			monster{ Monster::getRandomMonster() };
	    	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";
		}
		else
		{
			std::cout << "(R)un or (F)ight: ";
			std::cin >> choose;
			std::cout << std::endl;

			if(choose == 'f')
			{
				while(!monster.isDead())
				{
					std::cout << "You hit the " << monster.getName() << " for " << monster.getDamage() << "damage." << std::endl;
					monster.setHealth(monster.getHealth()-player.getDamage());

					if(monster.isDead())
					{
						/// update player stats
						player.levelUp();
						player.setGold(player.getGold()+monster.getGold());

						std::cout << "You killed the " << monster.getName() << '\n';
						std::cout << "You are now level " << player.getLevel() << "\n";
						std::cout << "You found " << player.getGold() << " gold." << std::endl;
						break;
					}
					else
					{
						std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << "damage." << std::endl;
					}	
				}
			}
			else
			{
				if(Random::get(0,1))
					std::cout << "You successfully fled!!!." << std::endl;
				else
				{
					std::cout << "You failed to flee." << "\n";
					std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage." << "\n";

					/// update player stats
					player.setHealth(player.getHealth()-monster.getDamage());

					if(player.isDead())
					{
						std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold." << "\n";
						std::cout << "Too bad you can't take it with you!" << std::endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}
/*************** GAME**************************************** */