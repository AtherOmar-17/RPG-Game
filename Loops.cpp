#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>
#include <locale>

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

int GetWeaponDamage(int weapon)
{
	switch (weapon)
	{
	case g_weaponNone:
		return 1 + rand() % 2;
		break;

	case g_weaponSword:
		return 4 + rand() % 3;
		break;

	case g_weaponAxe:
		return 2 + rand() % 7;
		break;

	default:
		return 0;
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

int GetArmorBonusHealth(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		return 0;
		break;

	case g_armorLight:
		return 10;
		break;

	case g_armorMedium:
		return 20;
		break;

	case g_armorHeavy:
		return 50;
		break;

	default:
		return 0;
	}
}

int GetArmorDodgeRate(int armor)
{
	switch (armor)
	{
	case g_armorNone:
		return 0;
		break;

	case g_armorLight:
		return 20;
		break;

	case g_armorMedium:
		return 10;
		break;

	case g_armorHeavy:
		return 0;
		break;

	default:
		return 0;
	}
}

void PressAnyKeyToContinue()
{
	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();
}

//Game logic

void Rest(int& playerHealth, int playerMaxHealth)
{
	constexpr int restHealing = 20;

	playerHealth = std::clamp(playerHealth + restHealing, 0, playerMaxHealth);
	std::cout << "You healed " << restHealing << "!" << std::endl;
	std::cout << "You now have " << playerHealth << " Health" << std::endl;

	PressAnyKeyToContinue();
}

void Round(int roundNumber, int& playerHealth, int playerWeapon, int playerArmor, int& enemyHealth, int enemyWeapon, int enemyArmor)
{
	system("cls");

	std::cout << "Round " << roundNumber << std::endl;

	int playerDodge = GetArmorDodgeRate(playerArmor);
	int enemyDodge = GetArmorDodgeRate(enemyArmor);

	int playerAttack = GetWeaponDamage(playerWeapon);
	int enemyAttack = GetWeaponDamage(enemyWeapon);

	if (playerDodge > rand() % 101)
	{
		std::cout << "You dodged the enemy's attack!" << std::endl;
		enemyAttack = 0;
	}

	if (enemyDodge > rand() % 101)
	{
		std::cout << "The enemy dodged your attack!" << std::endl;
		playerAttack = 0;
	}

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;

	enemyHealth = std::clamp(enemyHealth - playerAttack, 0, enemyHealth);
	playerHealth = std::clamp(playerHealth - enemyAttack, 0, playerHealth);

	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	PressAnyKeyToContinue();
}

void Encounter(int& playerHealth, int playerMaxHealth, int playerWeapon, int playerArmor)
{
	system("cls");

	int enemyHealth = 100;

	int enemyWeapon = rand() % g_weaponMax;
	std::string enemyWeaponName = GetWeaponName(enemyWeapon);

	int enemyArmor = rand() % g_armorMax;
	std::string enemyArmorName = GetArmorName(enemyArmor);

	enemyHealth += GetArmorBonusHealth(enemyArmor);

	std::cout << "You Encountered an Enemy" << std::endl;
	std::cout << "Their Health is: " << enemyHealth << std::endl;
	std::cout << "Their weapon is: " << enemyWeaponName << std::endl;
	std::cout << "Their armor is: " << enemyArmorName << std::endl;

	PressAnyKeyToContinue();

	for (int i = 1; playerHealth > 0 && enemyHealth > 0; i++)
	{
		Round(i, playerHealth, playerWeapon, playerArmor, enemyHealth, enemyWeapon, enemyArmor);
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

void PostEncounterOptions(bool& quit, int& playerHealth, int playerMaxHealth)
{
	std::cout << "What would you like to do now?" << std::endl;
	std::cout << "- Rest" << std::endl;
	std::cout << "- Quit" << std::endl;
	std::string choice;
	std::cin >> choice;

	if (choice == "Rest" || choice == "rest")
	{
		Rest(playerHealth, playerMaxHealth);
	}
	else if (choice == "Quit" || choice == "quit")
	{
		quit = true;
	}
}

void PlayGame()
{
	srand(time(NULL));

	std::cout << "Welcome to my RPG Game!" << std::endl;

	std::cout << "What is your name?" << std::endl;
	std::string name;
	std::cin >> name;

	system("cls");

	int playerMaxHealth = 100;

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

	playerMaxHealth += GetArmorBonusHealth(armor);

	int playerHealth = playerMaxHealth;

	std::cout << "Hello " << name << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "Your weapon of choice is: " << weaponName << std::endl;
	std::cout << "Your armor of choice is: " << armorName << std::endl;

	PressAnyKeyToContinue();

	bool quit = false;

	do 
	{
		Encounter(playerHealth, playerMaxHealth, weapon, armor);

		if (playerHealth > 0)
		{
			PostEncounterOptions(quit, playerHealth, playerMaxHealth);
		}
		else
		{
			quit = true;
		}

	} while (playerHealth > 0 && !quit);
}

int main()
{
	PlayGame();
}