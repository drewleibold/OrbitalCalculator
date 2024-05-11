#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ofstream myFile;
int NumberLove = 10;
int main() {
    myFile.open("Love.txt");
    myFile << "I love you, idiot. lmao :()\n";
    for (int i = 0; i < NumberLove; i++) {
        myFile << "I love YOU" << "\n";
    }
    myFile.close();
    return 0;
}