#include "common.h"

Void Search (ifstream &pFile, String &pInput);

int main ()
{
        ifstream file;
        String   input {};

    cout << "Enter the word to search: ";
    cin >> input;

    file.open ("../input.txt");

    if (!file) {

        cerr << "Error in opening the file!!" << endl;
        return 1;
    }

    Search (file, input);

    file.close ();

    return 0;
}

Void Search (ifstream &pFile, String &pInput)
{
        String word {};
        Int count {};
        Int words {};

    while (!pFile.eof ()) {

        pFile >> word;
        words++;

        if (word == pInput)
            count++;
    }

    cout << words << " were searched" << endl;
    cout << "The word " << pInput << " was found " << count << " times" << endl;
}
