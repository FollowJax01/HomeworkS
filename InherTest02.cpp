#include <iostream>
#include <memory>
using namespace std;

class Weapon
{
public:
    virtual float  getDamage() const = 0;
    virtual string getName() = 0;
};
class Axe : public Weapon
{
public:
    float getDamage()const override
    {
        return 40.1;
    }
    string getName() override
    {
        return "axe";
    }
};
class Sword : public Weapon
{
public:
    float getDamage() const override
    {
        return 22.3;
    }
    string getName() override
    {
        return "sword";
    }
};

class Character
{
public:
    unique_ptr<Weapon> weaponInfo;
    void SetWeapon(unique_ptr<Weapon> weapon)
    {
        weaponInfo = move(weapon);
    }
    unique_ptr<Weapon>& const GetWeapon() 
    {
        return weaponInfo;
    }
};

void inherTest02()
{
    {
        unique_ptr<Character> player_unique = make_unique<Character>();
        cout << endl;
        unique_ptr<Character> player_poher = move(player_unique);
        cout << endl;
        unique_ptr<Weapon> weapon_sword = make_unique<Sword>();
        unique_ptr<Weapon> weapon_axe = make_unique<Axe>();
        Character player;
        //Weapon* weapon_sword = new Sword();
        player.SetWeapon(move(weapon_sword));
        cout << "Player's weapon: " << player.GetWeapon()->getName() << ", Damage: " << player.GetWeapon()->getDamage() << std::endl;
        player.SetWeapon(move(weapon_axe));
        cout << "Player's weapon: " << player.GetWeapon()->getName() << ", Damage: " << player.GetWeapon()->getDamage() << std::endl;
        
    }


    
    
    {
       
        // //player_ptr - контейнер для хранения адресса объекта класса чарактер.
        // Character* player_ptr = new Character();
        // Character* player_ptr2 = player_ptr;
        // //удаляет данные по адрессу, освобождая ячейку памяти.
        // delete player_ptr;
        // player_ptr = nullptr;
        // Weapon* weapon_sword = new Sword();
        // cout << endl;
        // weapon_sword->getDamage();
        // weapon_sword->getName();
        // float sword_Damage = weapon_sword->getDamage();
        // cout << endl;
    }
    
    // Sword sword;
    // Axe axe;
    // player.SetWeapon(&sword);
    // std::cout << "Player's weapon: " << player.GetWeapon()->getName() << ", Damage: " << player.GetWeapon()->getDamage() << std::endl;
    //
    // player.SetWeapon(&axe);
    // std::cout << "Player's weapon: " << player.GetWeapon()->getName() << ", Damage: " << player.GetWeapon()->getDamage() << std::endl;
    //
}













//класс оружие с публичными virtual функциями гетнейм и гетдемедж
//классы-наследники от оружия (меч и топор) с оверрайд функциями гетнейм и гетдемедж

// Створити базовий клас Персонажа Character із методами 
// - void SetWeapon(Weapon* weapon); дає вепон персонажу
//
// - Weapon* GetWeapon() const; дає змогу дізнатися, що за вепон у персонажа
//
// Створити базовий клас Weapon із двома абстрактними методами
// - float GetDamage() = 0; повертає значення шкоди вепона
//
// - string GetName() = 0; повертає назву вепона
//
// Створити класи-нащадки різних видів вепонів


//Инкапсуляция - принцип ООП, ты должен по максимуму засовывать функционал в какой-то капсуль, для защиты, 