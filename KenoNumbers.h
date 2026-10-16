
#ifndef CSC_275_TEST1_KENONUMBERS_H
#define CSC_275_TEST1_KENONUMBERS_H
#include <vector>
using namespace std;

class KenoNumbers {
    private:
        vector<int> m_numbers = vector<int>(); // Ensure the variable points to an empty vector and not random memory space
    public:
        void generateNumbers();
        vector<int> getKenoNumbers();
        void printKenoNumbers();
        void clearKenoNumbers();


};


#endif //CSC_275_TEST1_KENONUMBERS_H
