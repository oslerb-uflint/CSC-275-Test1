#include "KenoNumbers.h"
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;


/* Abstraction is used here, the Game object doesn't
care how the numbers are generated, it just wants them to be generated */
void KenoNumbers::generateNumbers() {
    random_device rd;
    mt19937 gen(rd());
    gen.seed(0);
    uniform_int_distribution<> dis(1, 80);
    int num;
    for (int i = 1; i <= 20; i++) {
        do {
            num = dis(gen);
        }while (find(m_numbers.begin(), m_numbers.end(), num) != m_numbers.end());
        m_numbers.push_back(num);
    }
}

// The methods below all use encapsulation, they are all a step inbetween an external object accessing a member variable of this object
// In this case, they don't restrict access at all, but they could
void KenoNumbers::clearKenoNumbers() {
    m_numbers.clear();
}

vector<int> KenoNumbers::getKenoNumbers() {
    return m_numbers;
}

void KenoNumbers::printKenoNumbers() {
    sort(m_numbers.begin(), m_numbers.end()); //Only allow a sorted vector to be printed
    for (int m_number : m_numbers) {
        cout << m_number << " ";
    }
}
