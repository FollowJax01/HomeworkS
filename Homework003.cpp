#include <iostream>
#include <vector>
using namespace std;
struct Player
{
    enum Specialization
    {
        WARRIOR,MAGE

    };
    int id;
    Specialization spec;
    float melee;
    float ranged;

    Player(int player_id, Specialization spec, float melee, float ranged)
        : id(player_id),
          spec(spec),
          melee(melee),
          ranged(ranged)
    
    {
    }
};
int getStrongest(vector<Player> playerVector)
{
    int strongestId = -1;
    float strongestDamage = -1;
    for (const Player& player : playerVector)
    {
        float intermediateDamage = player.melee + player.ranged;
        if(strongestDamage < intermediateDamage)
        {
            strongestId = player.id;
            strongestDamage = intermediateDamage;
        }
    }
    return strongestId;
}
void Homework003(){
    //объект с именем игрока, содержащий параметры
    Player jarolineCastillo = Player(1, Player::Specialization::MAGE,0.1,4.5); 
    Player jarcoBi = Player(2, Player::Specialization::WARRIOR,0.7,0.5); 
    Player jinIvanova = Player(3, Player::Specialization::MAGE,0.1,1.5); 
    Player jlainYu = Player(4, Player::Specialization::WARRIOR,2.75,2.5); 
    Player jsabelMuhammed = Player(5, Player::Specialization::MAGE,16.1,3.5);

    vector<Player> playerVector;
    playerVector.push_back(jarolineCastillo);
    playerVector.push_back(jarcoBi);
    playerVector.push_back(jinIvanova);
    playerVector.push_back(jlainYu);
    playerVector.push_back(jsabelMuhammed);

    int result  = getStrongest(playerVector);
    cout << "Most powerful player is: " << result ;
    
}






//Створити свою структуру, в якій будуть наступні дані
// - ID персонажа : int
//
// - Клас персонажа : enum
//
// - Сила близкьої (melee) атаки  : float
//
// - Сила дальної (ranged) атаки : float
//
// Створити функцію, яка буде приймати на вхід вектор даних структур, та повертати id найсильнішого персонажа. 
// - Найсильніший – сума melee та ranged атак найбільша. 
//
// Завдання із зірочкою: 
// - Розробити функцію, яка поверне найсильнішого в кожному класі.

