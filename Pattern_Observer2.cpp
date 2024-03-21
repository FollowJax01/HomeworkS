#include <iostream>
#include <vector>
using namespace std;



class Observer
{
    //интерфейс для наблюдателя (подписчика на событие)
public:
    virtual void OnClick()=0;//метод будет вызван при  событии
};


//Класс, представляющий эвент (нажатие на кнопку)
class Button
{
private:
    std::vector<Observer*> observers;//вектор для хранения подписчиков


public:
    //метод для подписки на событие
    void subscribe (Observer* observer)
    {
        observers.push_back(observer);
    }
    //метод для симуляции щелчка по кнопке
    void Click()
    {
        //оповещаем всех подписчиков о событии
        for(Observer* observer : observers)
        {
            observer->OnClick();
        }
    }
};
    //класс подпищик
    class MessageSubscriber : public Observer
{
public:
    //вывод сообщения на экран
    void OnClick() override
    {
        cout << "Button Pressed! Message Out!" << endl;
    }
};


int observer2()
{
    Button knopka;
    MessageSubscriber podpisota;
    knopka.subscribe(&podpisota);
    knopka.Click();
 
    return 0;
}






//класс - событие, щелчок по кнопке, на него должны подписываться другие части кода и как-то реагировать на клик