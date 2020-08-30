#include "common.h"

Void Display (ifstream &pFile);

int main ()
{
        ifstream file;

    file.open ("../sample.txt");

    if (!file) {

        cerr << "Error in opening the file!!" << endl;
        return 1;
    }

    Display (file);

    file.close ();

    return 0;
}

Void Display (ifstream &pFile)
{
        String ans {};
        String line {};
        Int    score {};
        Int    sum {};
        Int    count {};
        Int    len {};

    getline (pFile, ans);
    len = ans.length ();

    cout << setw (20) << left << "Student";
    cout << setw (7) << right << "Score" << endl;
    cout << "---------------------------" << endl;

    while (std::getline (pFile, line)) {

        cout << setw (20) << left << line;

        getline (pFile, line);

        for (Int i = 0; i < len; i++)
            if (ans[i] == line[i])
                score++;
            
        cout << setw (7) << right << score << endl;
        
        sum += score;
        score = 0;
        count++;
    }

    cout << "---------------------------" << endl;

    cout << setw (20) << left << "Average score";
    cout << setw (7) << right << static_cast <Double> (sum) / count << endl;
}
