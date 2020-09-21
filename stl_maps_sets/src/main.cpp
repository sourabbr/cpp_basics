#include "common.h"

Void CountWords (ifstream &pFile);
Void Display (const std::map <String, Int> &pWords1, const std::map <String, std::set <Int>> &pWords2);
String CleanString (String &pStr);

int main ()
{
        ifstream file;

    file.open ("../words.txt");

    if (!file) {

        cerr << "Error in opening the file!!" << endl;
        return 1;
    }

    CountWords (file);

    file.close ();

    return 0;
}

Void CountWords (ifstream &pFile)
{
        std::map <String, Int> words1;
        std::map <String, std::set <Int>> words2;
        String line {};
        String word {};
        Int line_count {0};

    while (std::getline (pFile, line)) {

        line_count++;

        std::istringstream ss {line};

        while (ss >> word) {

            word = CleanString (word);
            words1[word]++;    
            words2[word].insert (line_count);         
        }              
    }

    Display (words1, words2);
}

Void Display (const std::map <String, Int> &pWords1, const std::map <String, std::set <Int>> &pWords2)
{
    cout << "Part 1: " << endl;
    cout << std::setw (20) << std::left << "Words"
         << std::setw (5) << std::right << "Count" << endl;
    cout << "=========================" << endl;

    for (const auto pair: pWords1) {

        cout << std::setw (20) << std::left << pair.first
         << std::setw (5) << std::right << pair.second << endl; 
    }

    cout << endl << endl;

    cout << "Part 2: " << endl;  
    cout << std::setw (20) << std::left << "Words"
         << std::left << "Lines" << endl;
    cout << "=========================" << endl;
    for (const auto pair: pWords2) {

        cout << std::setw (20) << std::left << pair.first
         << std::left << "[ ";

        for (const auto i: pair.second)
            cout << i << " ";

        cout << "]" << endl;
    }
}

String CleanString (String &pStr)
{
    String str {};

    for (char c:pStr) {

        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            str += c;
    }

    return str;
}
