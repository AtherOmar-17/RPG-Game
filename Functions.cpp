#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>

constexpr int g_weaponNone = 0;
constexpr int g_weaponSword = 1;
constexpr int g_weaponAxe = 2;
constexpr int g_weaponMax = 3;

constexpr int g_armorNone = 0;
constexpr int g_armorLight = 1;
constexpr int g_armorMedium = 2;
constexpr int g_armorHeavy = 3;
constexpr int g_armorMax = 4;

//Helper functions

std::string GetWeaponName(int weapon)
{
	switch (weapon)
	{
	case g_weaponNone:
		return "None";
		break;

	case g_weaponSword:
		return "Sword";
		break;

	case g_weaponAxe:
		return "Axe";
		break;

	default:
		return "Unknown";
	}
}

std::string GetArmorName(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		return "None";
		break;

	case g_armorLight:
		return "Light Armor";
		break;

	case g_armorMedium:
		return "Medium Armor";
		break;

	case g_armorHeavy:
		return "Heavy Armor";
		break;

	default:
		return "Unknown";
	}
}

void PressAnyKeyToContinue()
{
	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();
}

//Game logic

void Rest(int& playerHealth)
{
	std::cout << "Would you like to rest before the next encounter? (y/n)" << std::endl;
	char choice = 'n';
	std::cin >> choice;

	constexpr int restHealing = 20;

	if (choice == 'y')
	{
		playerHealth = std::clamp(playerHealth + restHealing, 0, 100);
		std::cout << "You healed " << restHealing << "!" << std::endl;
		std::cout << "You now have " << playerHealth << " Health" << std::endl;
	}
}

void Round(int roundNumber, int& playerHealth, int& enemyHealth)
{
	system("cls");

	std::cout << "Round " << roundNumber << std::endl;

	int playerAttack = 5 + rand() % 6;
	int enemyAttack = 4 + rand() % 4;

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;

	enemyHealth = std::clamp(enemyHealth - playerAttack, 0, 100);
	playerHealth = std::clamp(playerHealth - enemyAttack, 0, 100);

	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	PressAnyKeyToContinue();
}

void Encounter(int& playerHealth)
{
	system("cls");

	int enemyHealth = 100;

	int enemyWeapon = rand() % g_weaponMax;
	std::string enemyWeaponName = GetWeaponName(enemyWeapon);

	int enemyArmor = rand() % g_armorMax;
	std::string enemyArmorName = GetArmorName(enemyArmor);

	std::cout << "You Encountered an Enemy" << std::endl;
	std::cout << "Their Health is: " << enemyHealth << std::endl;
	std::cout << "Their weapon is: " << enemyWeaponName << std::endl;
	std::cout << "Their armor is: " << enemyArmorName << std::endl;

	PressAnyKeyToContinue();

	Round(1, playerHealth, enemyHealth);

	if (playerHealth > 0 && enemyHealth > 0)
	{
		Round(2, playerHealth, enemyHealth);
	}

	if (playerHealth > 0 && enemyHealth > 0)
	{
		Round(3, playerHealth, enemyHealth);
	}

	if (playerHealth > 0 && enemyHealth > 0)
	{
		Round(4, playerHealth, enemyHealth);
	}

	if (playerHealth > 0 && enemyHealth > 0)
	{
		Round(5, playerHealth, enemyHealth);
	}

	system("cls");

	std::cout << "You have " << playerHealth << " Health Left" << std::endl;
	std::cout << "The Enemy has " << enemyHealth << " Health Left" << std::endl;

	if (playerHealth > enemyHealth)
	{
		std::cout << "You Win!" << std::endl;
	}
	else if (playerHealth < enemyHealth)
	{
		std::cout << "You Lose..." << std::endl;
	}
	else
	{
		std::cout << "It's a tie?" << std::endl;
	}

	PressAnyKeyToContinue();
}

void PlayGame()
{
	srand(time(NULL));

	std::cout << "Welcome to my RPG Game!" << std::endl;

	std::cout << "What is your name?" << std::endl;
	std::string name;
	std::cin >> name;

	system("cls");

	int playerHealth = 100;

	std::cout << "Choose your weapon" << std::endl;
	std::cout << g_weaponSword << ") Sword" << std::endl;
	std::cout << g_weaponAxe << ") Axe" << std::endl;
	int weapon = 0;
	std::cin >> weapon;

	std::string weaponName = GetWeaponName(weapon);

	system("cls");

	std::cout << "Choose your armor" << std::endl;
	std::cout << g_armorLight << ") Light" << std::endl;
	std::cout << g_armorMedium << ") Medium" << std::endl;
	std::cout << g_armorHeavy << ") Heavy" << std::endl;
	int armor = 0;
	std::cin >> armor;

	std::string armorName = GetArmorName(armor);

	system("cls");

	std::cout << "Hello " << name << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "Your weapon of choice is: " << weaponName << std::endl;
	std::cout << "Your armor of choice is: " << armorName << std::endl;

	PressAnyKeyToContinue();

	Encounter(playerHealth);

	if (playerHealth > 0)
	{
		Rest(playerHealth);
	}

	if (playerHealth > 0)
	{
		Encounter(playerHealth);

		if (playerHealth > 0)
		{
			Rest(playerHealth);
		}
	}

	if (playerHealth > 0)
	{
		Encounter(playerHealth);

		if (playerHealth > 0)
		{
			Rest(playerHealth);
		}
	}
}

int main()
{
	PlayGame();
}