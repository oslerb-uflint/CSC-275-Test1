#include <vector>
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include "KenoNumbers.h"
using namespace std;

Game::Game() {
    m_keno = KenoNumbers();
    m_player = Player();
    playGame();
}

void Game::printMatches(vector<int> playerPicks, vector<int> kenoNumbers) {
    for (int num: playerPicks) {
        if (find(kenoNumbers.begin(), kenoNumbers.end(), num) != kenoNumbers.end()) {
            m_matches.push_back(num); // this vector will already be sorted because playerPicks is sorted
            cout<<num<<" ";
        }
    }
}

void Game::displayResults() {
    cout <<"\n----------------------------------Results----------------------------------\n";
    cout << "Keno Numbers: ";
    m_keno.printKenoNumbers(); // print the sorted vector of Keno numbers
    cout << endl;
    cout << "Player Picks: ";
    m_player.printPlayerNumbers(); // print the sorted vector of player choices
    cout << endl;
    cout << "You matched: ";
    printMatches(m_player.getPlayerNumbers(), m_keno.getKenoNumbers()); // fill the m_matches vector and display any matches found
    if (m_matches.size() > 0) {
        cout<<"\nMatching " << m_matches.size() << " of 20 numbers wins ";
        switch (m_matches.size()){
            case 10:
                cout<<"the GRAND PRIZE of $250,000";
                break;
            case 9:
                cout << "$2,500";
                break;
            case 8:
                cout<<"$250";
                break;
            case 7:
                cout<<"$50";
                break;
            case 6:
                cout<<"$10";
                break;
            case 5:
                cout<<"$5";
                break;
            default:
                cout<<"$0. Sorry, better luck next time.";
        }
    }
    else {
        cout << "\nSorry, you didn't have any matches.";
    }
}

void Game::playGame() {
    bool playAgain = false;
    do {
        // Ensure no leftover values from previous rounds or other artifacts are in the data
        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        m_matches.clear();
        // print rules
        cout<<"To play Keno, select 10 unique (no repeats) numbers in the range of 1-80."<<endl<<endl;
        cout<<"Let's Play Keno!"<<endl;
        m_player.inputPlayerNumbers(); // Get the player's choices
        m_keno.generateNumbers(); // Generate "random" sequence of Keno Numbers in the m_keno object
        displayResults(); // display the results of the game
        char choice;
        do {
            cout<<endl<<"Play another round? (y/n): ";
            cin>>choice;
            choice = tolower(choice);
            if (choice != 'y'&&choice != 'n') {
                cout<<endl<<"Invalid input. Please try again.";
            }
        }while (choice != 'y'&&choice != 'n'); // validate choice is either yes or no
        switch (choice) {
            case 'y':
                playAgain = true;
                break;
            case 'n':
                playAgain = false;
                break;
        }
    }while (playAgain);

    cout<<endl<<endl<<"THANKS FOR PLAYING!!";
}
