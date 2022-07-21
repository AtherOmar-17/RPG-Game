#include <iostream>
#include <string>
#include <time.h>

constexpr int g_weaponNone = 0;
constexpr int g_weaponSword = 1;
constexpr int g_weaponAxe = 2;
constexpr int g_weaponMax = 3;

constexpr int g_armorNone = 0;
constexpr int g_armorLight = 1;
constexpr int g_armorMedium = 2;
constexpr int g_armorHeavy = 3;
constexpr int g_armorMax = 4;

int main()
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

	std::string weaponName;

	switch (weapon)
	{
	case g_weaponNone:
		weaponName = "None";
		break;

	case g_weaponSword:
		weaponName = "Sword";
		break;

	case g_weaponAxe:
		weaponName = "Axe";
		break;

	default:
		weaponName = "Unknown";
	}

	system("cls");

	std::cout << "Choose your armor" << std::endl;
	std::cout << g_armorLight << ") Light" << std::endl;
	std::cout << g_armorMedium << ") Medium" << std::endl;
	std::cout << g_armorHeavy << ") Heavy" << std::endl;
	int armor = 0;
	std::cin >> armor;

	std::string armorName;

	switch (armor)
	{
	case g_armorNone:
		armorName = "None";
		break;

	case g_armorLight:
		armorName = "Light Armor";
		break;

	case g_armorMedium:
		armorName = "Medium Armor";
		break;

	case g_armorHeavy:
		armorName = "Heavy Armor";
		break;

	default:
		armorName = "Unknown";
	}

	system("cls");

	std::cout << "Hello " << name << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "Your weapon of choice is: " << weaponName << std::endl;
	std::cout << "Your armor of choice is: " << armorName << std::endl;

	int enemyHealth = 100;

	int enemyWeapon = rand() % g_weaponMax;
	std::string enemyWeaponName;

	switch (enemyWeapon)
	{
	case g_weaponNone:
		enemyWeaponName = "None";
		break;

	case g_weaponSword:
		enemyWeaponName = "Sword";
		break;

	case g_weaponAxe:
		enemyWeaponName = "Axe";
		break;

	default:
		enemyWeaponName = "Unknown";
	}

	int enemyArmor = rand() % g_armorMax;
	std::string enemyArmorName;

	switch (enemyArmor)
	{
	case g_armorNone:
		enemyArmorName = "None";
		break;

	case g_armorLight:
		enemyArmorName = "Light Armor";
		break;

	case g_armorMedium:
		enemyArmorName = "Medium Armor";
		break;

	case g_armorHeavy:
		enemyArmorName = "Heavy Armor";
		break;

	default:
		enemyArmorName = "Unknown";
	}

	std::cout << "You Encountered an Enemy"<< std::endl;
	std::cout << "Their Health is: " << enemyHealth << std::endl;
	std::cout << "Their weapon is: " << enemyWeaponName << std::endl;
	std::cout << "Their armor is: " << enemyArmorName << std::endl;

	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();

	system("cls");

	std::cout << "Round 1" << std::endl;

	int playerAttack = 5 + rand() % 6;
	int enemyAttack = 4 + rand() % 4;

	enemyHealth -= playerAttack;
	playerHealth -= enemyAttack;

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();

	system("cls");

	std::cout << "Round 2" << std::endl;

	playerAttack = 5 + rand() % 6;
	enemyAttack = 4 + rand() % 4;

	enemyHealth -= playerAttack;
	playerHealth -= enemyAttack;

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();

	system("cls");

	std::cout << "Round 3" << std::endl;

	playerAttack = 5 + rand() % 6;
	enemyAttack = 4 + rand() % 4;

	enemyHealth -= playerAttack;
	playerHealth -= enemyAttack;

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();

	system("cls");

	std::cout << "Round 4" << std::endl;

	playerAttack = 5 + rand() % 6;
	enemyAttack = 4 + rand() % 4;

	enemyHealth -= playerAttack;
	playerHealth -= enemyAttack;

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	std::cout << "Press any key to continue" << std::endl;
	std::cin.ignore();
	std::cin.get();

	system("cls");

	std::cout << "Round 5" << std::endl;

	playerAttack = 5 + rand() % 6;
	enemyAttack = 4 + rand() % 4;

	enemyHealth -= playerAttack;
	playerHealth -= enemyAttack;

	std::cout << "You Dealt: " << playerAttack << " Damage!" << std::endl;
	std::cout << "You took: " << enemyAttack << " Damage!" << std::endl;
	std::cout << "Your Health is: " << playerHealth << std::endl;
	std::cout << "The Enemy Health is: " << enemyHealth << std::endl;

	std::cout << std::endl;

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
}