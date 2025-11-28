#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <stdexcept>
#include <algorithm>

class Calculator {
public:
    // 1. Пошук мінімального елементу масиву позитивних чисел
    static double findMinPositive(const std::vector<double>& arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Масив не може бути порожнім");
        }
        
        for (const auto& num : arr) {
            if (num <= 0) {
                throw std::invalid_argument("Всі числа повинні бути позитивними");
            }
        }
        
        return *std::min_element(arr.begin(), arr.end());
    }
    
    // 2. Розрахунок суми елементів масиву від'ємних чисел
    static double sumNegative(const std::vector<double>& arr) {
        if (arr.empty()) {
            throw std::invalid_argument("Масив не може бути порожнім");
        }
        
        for (const auto& num : arr) {
            if (num >= 0) {
                throw std::invalid_argument("Всі числа повинні бути від'ємними");
            }
        }
        
        double sum = 0;
        for (const auto& num : arr) {
            sum += num;
        }
        
        return sum;
    }
    
    // 3. Алгоритм розрахунку N-го елементу послідовності Фібоначчі
    static long long fibonacci(int n) {
        if (n < 0) {
            throw std::invalid_argument("n повинно бути невід'ємним числом");
        }
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long long prev = 0, curr = 1;
        for (int i = 2; i <= n; i++) {
            long long next = prev + curr;
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
    
    // 4. Алгоритм розрахунку сили струму на ділянці кола (I = U / R)
    static double calculateCurrent(double voltage, double resistance) {
        if (resistance <= 0) {
            throw std::invalid_argument("Опір повинен бути більшим за нуль");
        }
        
        return voltage / resistance;
    }
};

#endif // CALCULATOR_H