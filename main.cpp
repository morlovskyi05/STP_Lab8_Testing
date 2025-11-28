#include "Calculator.h"
#include <iostream>
#include <iomanip>

void printSeparator() {
    std::cout << std::string(60, '=') << std::endl;
}

void demonstrateFindMinPositive() {
    std::cout << "\n1. Пошук мінімального елементу масиву позитивних чисел\n";
    printSeparator();
    
    std::vector<double> arr = {5.5, 2.3, 8.1, 1.7, 4.2};
    std::cout << "Масив: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nМінімальний елемент: " << Calculator::findMinPositive(arr) << std::endl;
}

void demonstrateSumNegative() {
    std::cout << "\n2. Розрахунок суми елементів масиву від'ємних чисел\n";
    printSeparator();
    
    std::vector<double> arr = {-1.5, -2.5, -3.0, -4.0};
    std::cout << "Масив: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\nСума елементів: " << Calculator::sumNegative(arr) << std::endl;
}

void demonstrateFibonacci() {
    std::cout << "\n3. Розрахунок N-го елементу послідовності Фібоначчі\n";
    printSeparator();
    
    std::cout << "Перші 15 чисел Фібоначчі:\n";
    for (int i = 0; i < 15; i++) {
        std::cout << "F(" << std::setw(2) << i << ") = " 
                  << std::setw(6) << Calculator::fibonacci(i) << std::endl;
    }
}

void demonstrateCalculateCurrent() {
    std::cout << "\n4. Розрахунок сили струму на ділянці кола (I = U / R)\n";
    printSeparator();
    
    double voltage = 220.0;
    double resistance = 10.0;
    double current = Calculator::calculateCurrent(voltage, resistance);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Напруга: " << voltage << " В\n";
    std::cout << "Опір: " << resistance << " Ом\n";
    std::cout << "Сила струму: " << current << " А\n";
}

int main() {
    std::cout << "\n";
    printSeparator();
    std::cout << "  ДЕМОНСТРАЦІЯ РОБОТИ КЛАСУ CALCULATOR\n";
    printSeparator();
    
    try {
        demonstrateFindMinPositive();
        demonstrateSumNegative();
        demonstrateFibonacci();
        demonstrateCalculateCurrent();
        
        std::cout << "\n";
        printSeparator();
        std::cout << "  ВСІ ОПЕРАЦІЇ ВИКОНАНІ УСПІШНО!\n";
        printSeparator();
        std::cout << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}