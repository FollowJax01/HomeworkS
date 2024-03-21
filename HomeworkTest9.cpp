#include <iostream>
#include <vector>
using namespace std;
class building
{
public:
   //конструктор класса билдинг
    building( int MaxAge, float initCost)
        :
         maxAge(MaxAge),
         initialCost(initCost)
    {
        buildingID = nextBuildingID;
        nextBuildingID ++;
        yearsPassed = 0;
    }
    
   void toAge(int years)
    {
        yearsPassed += years;
        if(yearsPassed > maxAge)
        {
            destroy();
        }
    }

    float GetCost()
    {
        if(yearsPassed > maxAge)
        {
            return 0;
        }else{
        //вартість в х рік = початкова ціна - (початкава/макс кільк років) * прошедші роки
        return initialCost - (initialCost/maxAge) * yearsPassed;
        }     //5000 - (5000/30) * 30
    }
private:
    int buildingID;
    int maxAge;
    float initialCost;
    int yearsPassed;
    static int nextBuildingID;
    
    void destroy()
    {
        cout << "Building with id: " << buildingID  << " Was destroyed" << endl;
    }
};
int building::nextBuildingID = 1;

int test9()
{
    
    building building1 ( 20, 5000);
    building building2 ( 30, 5000);
    building building3 ( 27, 5000);
    int yearsPassed;
    building1.toAge(21);
    building2.toAge(10);
    building3.toAge(12);
    cout << building1.GetCost() << endl;
    cout << building2.GetCost() << endl;
    cout << building3.GetCost() << endl;
    
    return 0;
}






// // Для симулятора міста розробіть клас Building із наступними змінними
// // - Id: int (повинен бути унікальний для всіх будівель)
// // 
// // - MaxAge: int – максимальна кількість років, яка ця будівля простоїть\
// //
// // - Initial Cost: int – початкова вартість будівлі
// //
// // В цього класса повинні бути наступні функції-члени:
// // - Int GetCost();
// //
// // * Повертає поточну вартість будівлі. Із кожним роком вартість будівлі зменшується лінійно: 0 років – initial cost, MaxAge років – 0$, MaxAge/2 – InitialCost/2
// //
// // - void ToAge(int years);
// //
// // * Виклик цієї функції повинен зістарити будівлю на year років
// //
// // * Якщо будівля зістарилася більше, ніж її максимальний вік, то вона повинна викликати приватну фукцію Destroy();
// //
// // - void Destroy();
// //
// // * Приватна функція, яка в косноль повідомить будівля із яким id була знищенна
//
