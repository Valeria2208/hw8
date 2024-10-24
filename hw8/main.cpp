//
//  main.cpp
//  hw8
//
//  Created by Valeria Dudinova on 24.10.2024.
//

#include <iostream>
using namespace std;

class SlotMachine
{
private:
    char symbols[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char reels[3];
    int position;

public:
    // Конструктор ініціалізації
    SlotMachine() : position(0) {}

    // Метод для обертання барабанів
    void spin()
    {
        for (int i = 0; i < 3; ++i)
        {
            reels[i] = symbols[(position + i) % 6];  // Вибираємо символи з масиву
        }
        position = (position + 1) % 6;  // Змінюємо початкову позицію для наступного обертання
    }

    // Метод для виведення результату обертання
    void displayReels()
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << reels[i] << " ";
        }
        cout << endl;
    }

    // Перевірка на виграш (якщо всі символи однакові)
    bool checkWin()
    {
        return (reels[0] == reels[1] && reels[1] == reels[2]);
    }

    // Виведення результату гри
    void showResult()
    {
        if (checkWin())
        {
            cout << "YOU WIN" << endl;
        }
        else
        {
            cout << "You lost. Try again!" << endl;
        }
    }
};

int main()
{
    SlotMachine machine;
    char playAgain;

    do
    {
        cout << "Press Enter to spin the reels...";
        cin.get();  // Чекаємо натискання клавіші

        machine.spin();          // Обертаємо барабани
        machine.displayReels();  // Виводимо символи на екрані

        machine.showResult();    // Перевіряємо результат гри

        cout << "Play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();  // Ігноруємо залишковий символ нового рядка

    }
    while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
