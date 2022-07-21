#include <iostream>
#include <string>

constexpr int g_weaponNone = 0;
constexpr int g_weaponSword = 1;
constexpr int g_weaponAxe = 2;

constexpr int g_armorNone = 0;
constexpr int g_armorLight = 1;
constexpr int g_armorMedium = 2;
constexpr int g_armorHeavy = 3;

int main()
{
	std::cout << "Welcome to my RPG Game!" << std::endl;

	std::cout << "What is your name?" << std::endl;
	std::string name;
	std::cin >> name;

	int playerHealth = 100;

	std::cout << "Choose your weapon" << std::endl;
	std::cout << g_weaponSword << ") Sword" << std::endl;
	std::cout << g_weaponAxe << ") Axe" << std::endl;
	int weapon = 0;
	std::cin >> weapon;

	std::cout << "Choose your armor" << std::endl;
	std::cout << g_armorLight << ") Light" << std::endl;
	std::cout << g_armorMedium << ") Medium" << std::endl;
	std::cout << g_armorHeavy << ") Heavy" << std::endl;
	int armor = 0;
	std::cin >> armor;

	std::cout << "Hello " << name << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "Your weapon of choice is: " << weapon << std::endl;
	std::cout << "Your armor of choice is: " << armor << std::endl;
}