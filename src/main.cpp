#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int NumberLove = 10;
int LineCount = 0;
string UserFile;
string myText;

int main(int argc, char *argv[]) {
    if (argc ==  2) {
        UserFile = argv[1];
    } else if (argc == 1) {
        UserFile = "input/read.txt";
    } else {
        fprintf(stderr, "You screwed up. Input an argument into the command line following the program executable or just leave executable as is without arguments.\n");
        return 1;
    }
    ifstream myReadFile(UserFile);
    ofstream myOutFile(UserFile);
    //do file stuff here
    while (getline(myReadFile, myText)) {
        
    }

    myReadFile.close();
    return 0;
}

/*
    while (getline(myFile, myText)) {
        if (myText == ) {

        }
    }
    */