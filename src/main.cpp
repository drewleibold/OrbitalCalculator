#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int NumberLove = 10;
int NounCount = 0;
string UserFile;
string UserWord;
string myReadText;
string myOutText;
vector<string> nouns;

int main(int argc, char *argv[]) {
    if (argc ==  3) {
        UserFile = argv[1];
        UserWord = argv[2];
    } else if (argc == 2) {
        UserFile = "input/read.txt";
        UserWord = argv[1];
    } else if (argc == 1) {
        UserFile = "input/read.txt";
        UserWord = "poop";
    } else {
        fprintf(stderr, "You screwed up. See Example: \n(Executable) file-path word-to-use");
        return 1;
    }

    //looking at the number of nouns we want to replace.

    ifstream myReadFile(UserFile);
    ifstream myWordFile("input/nouns.txt");
    ofstream myOutFile("BetterText.txt");

    while (getline(myWordFile, myReadText)) {
        nouns.push_back(myReadText);
        NounCount++;
    } //just runs through the file one time then has to reset if you want to use it.
    printf("Number of Nouns: %d\n", NounCount);
    //checking validity of stupid user.
    if (!myReadFile.is_open()) {
        fprintf(stderr, "You screwed up. The first argument needs to be a valid file path. The second argument is the word you want to replace with.\n");
        return 1;
    }
    //do file stuff here
    //still have to find a way to get through the punctuation. They wrote this bible sturdy.
    while (getline(myReadFile, myReadText, ' ')) {
        bool isWordReplace = false;
        for (int i = 0; i < NounCount; i++) {
            string nounElem = nouns.at(i);

            if (myReadText.compare(nounElem) == 0 and !isWordReplace) {
                cout << "My Read In Word: " + myReadText + " and my noun element: " + nounElem << "\n";
                myOutFile << UserWord << " ";
                isWordReplace = true;
                break;
            }
            
        }
        if (isWordReplace) {
            continue;
        }
        myOutFile << myReadText << " ";
    }

    myReadFile.close();
    myOutFile.close();
    myWordFile.close();
    return 0;
}

/*
    while (getline(myFile, myText)) {
        if (myText == ) {

        }
    }
    */