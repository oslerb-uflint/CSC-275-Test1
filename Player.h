
#ifndef CSC_275_TEST1_PLAYER_H
#define CSC_275_TEST1_PLAYER_H
#include <vector>
using namespace std;


class Player {
    private:
        vector<int> m_playerNumbers =vector<int>(); // Ensure the variable points to an empty vector and not random memory space
    public:
        void inputPlayerNumbers();
        vector<int> getPlayerNumbers();
        void printPlayerNumbers();
        void clearPlayerNumbers();


};


#endif //CSC_275_TEST1_PLAYER_H
