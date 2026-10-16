#include "Player.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/* Abstraction is used here, the Game object doesn't care how
the player inputs are retrieved, it just wants there to be player inputs */
void Player::inputPlayerNumbers() {
    int choice =0;
    for(int i=1;i<=10;i++) {
        cout<<endl;
        do {
            cout<<"Enter your pick #"<<i<<": ";
            cin>>choice;
            if (cin.fail()) {
                cin.clear();
                cin.sync();
                cout <<endl<< "Invalid data input! Try again. ";
            } else if (choice < 1 || choice > 80) {
                cout << endl<<choice << " is out of range! Try again. ";
            } else if (find(m_playerNumbers.begin(), m_playerNumbers.end(), choice) != m_playerNumbers.end() ) {
                cout << endl<< choice << " was already picked! Try again. ";
                choice = 0;
            }else {
                m_playerNumbers.push_back(choice);
            }
        }while (choice >80||choice < 1);
    }
}

// The methods below all use encapsulation, they are all a step inbetween an external object accessing a member variable of this object
// In this case, they don't restrict access at all, but they could
vector<int> Player::getPlayerNumbers() {
    return m_playerNumbers;
}
void Player::clearPlayerNumbers() {
    m_playerNumbers.clear();
}

void Player::printPlayerNumbers() {
    sort(m_playerNumbers.begin(), m_playerNumbers.end()); //Only allow a sorted vector to be printed
    for (int number:m_playerNumbers) {
        cout<<number<<" ";
    }
}