// Yungman_Pr2_ST.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//Задание 3 Структуры:
struct WeatherInfo {
    double temperature;
    double humidity;
    double windSpeed;
};

//Задание 4 Классы:
class Client {
public:
    std::string name;
    int id;
    double balance;

    Client() : name(""), id(0), balance(0.0) {}
    void displayInfo() 
    {
        std::cout << "ID: " << id << ", Имя: " << name
            << ", Баланс:" << balance << std::endl;
    }
};

class Bank 
{
private:
    Client clients[100];
    int clientsCount;

public:
    Bank() 
    {
        clientsCount = 0;
    }

    void plus(int id, double sum) 
    {
        for (int i = 0; i < clientsCount; i++) 
        {
            if (clients[i].id == id)
            {
                if (sum > 0) 
                {
                    clients[i].balance += sum;
                }
                return;
            }
        }
    }

    bool minus(int id, double sum) 
    {
        for (int i = 0; i < clientsCount; i++) 
        {
            if (clients[i].id == id)
            {
                if (sum > 0 && clients[i].balance >= sum) 
                {
                    clients[i].balance -= sum;
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void newChet(std::string name, int id, double balance)
    {
        if (clientsCount < 100) 
        {
            clients[clientsCount].name = name;
            clients[clientsCount].id = id;
            clients[clientsCount].balance = balance;
            clientsCount++;
        }
    }

    void Info(int id) 
    {
        for (int i = 0; i < clientsCount; i++) 
        {
            if (clients[i].id == id)
            {
                clients[i].displayInfo();
                return;
            }
        }
        std::cout << "Клиента с таким id нет " << std::endl;
    }
};
int main() {
    setlocale(0, "rus");

    //задание 1 Одномерные массивы
    const int n = 5;
    int mas[n] = { 1 ,2, 3, 4, 5 };
    int newmas[n];

    newmas[0] = mas[0];
    for (int i = 1;i < n;i++)
    {
        newmas[i] = newmas[i - 1] + mas[i];
    }

    std::cout << "Начальный массив" << std::endl;
    for (int i = 0;i < n;i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Массив, где каждый элемент равен сумме предыдущих элементов." << std::endl;
    for (int i = 0;i < n;i++)
    {
        std::cout << newmas[i] << " ";
    }

    //Задание 2 Многомерные массивы:
    std::cout << std::endl;
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    std::cout << "Начальный массив:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4/2; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[i][4 - 1 - j];
            arr[i][4 - 1 - j] = temp;
        }
    }
    std::cout << "Перевернутый массив:" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //Задание 3 Структуры:
    WeatherInfo info;
    std::cout << "Введите температуру на сегодня";
    std::cin >> info.temperature;

    std::cout << "Введите влажность";
    std::cin >> info.humidity;

    std::cout << "Введите скорость ветра ";
    std::cin >> info.windSpeed;

    std::cout << "Прогноз погоды\n";
    if (info.temperature > 25) 
    {
        std::cout << "Сегодня жарко" << info.temperature << "°C" << std::endl;
    }
    else if (info.temperature > 15) 
    {
        std::cout << "Сегодня тепло" << info.temperature << "°C" << std::endl;
    }
    else if (info.temperature > 5) 
    {
        std::cout << "Сегодня довольно холодно" << info.temperature << "°C" << std::endl;
    }
    else 
    {
        std::cout << "Сегодня холодно" << info.temperature << "°C" << std::endl;
    }
    if (info.humidity > 80) 
    {
        std::cout << "Высокая влажность" << info.humidity << "%" << std::endl;
    }
    else if (info.humidity > 50) 
    {
        std::cout << "Влажность нормальная" << info.humidity << "%" << std::endl;
    }
    else 
    {
        std::cout << "Низкая влажность" << info.humidity << "%" << std::endl;
    }
    if (info.windSpeed > 10) 
    {
        std::cout << "Сильный ветер" << info.windSpeed << "м/с" << std::endl;
    }
    else if (info.windSpeed > 5) 
    {
        std::cout << "Умеренный ветер" << info.windSpeed << "м/с" << std::endl;
    }
    else 
    {
        std::cout << "Слабый ветер" << info.windSpeed << "м/с" << std::endl;
    }

    //Задание 4 Классы:
    Bank bank;
    bank.newChet("Денис Николаевич", 1, 500.0);
    bank.newChet("Лев Алексеевич", 2, 1000.0);
 
    bank.Info(1);
    bank.Info(2);

    std::cout << std::endl;
    bank.plus(1, 800.0);
    bank.Info(1);

    std::cout << std::endl;
    bank.minus(2, 300.0);
    bank.Info(2);

    return 0;

}

