
#ifndef CSC_275_TEST1_GAME_H
#define CSC_275_TEST1_GAME_H
#include "KenoNumbers.h"
#include "Player.h"
#include <vector>
using namespace std;

class Game {
    private:
        KenoNumbers m_keno;
        Player m_player;
        vector<int> m_matches = vector<int>(); // Ensure the variable points to an empty vector and not random memory space
    public:
        Game(); // All methods under the default constructor could be private, they are all only called by the Game object.
        void printMatches(vector<int> playerPicks, vector<int> kenoNumbers);
        void displayResults();
        void playGame();

};


#endif //CSC_275_TEST1_GAME_H
