#include "common.h"

Bool Copy (ifstream &pInput, ofstream &pOutput);

int main ()
{
        ifstream in_file;
        ofstream out_file;

    in_file.open ("../input.txt");

    if (!in_file) {

        cerr << "Error in opening the input file!!" << endl;
        return 1;
    }

    out_file.open ("../output.txt");

    if (!out_file) {

        cerr << "Error in opening the output file!!" << endl;
        return 1;
    }

    if (Copy (in_file, out_file))
        cout << "Copy successfull" << endl;
    else
        cout << "Copy failed" << endl;

    in_file.close ();
    out_file.close ();

    return 0;
}

Bool Copy (ifstream &pInput, ofstream &pOutput)
{
        String line {};
        Int    line_no {1};

    while (getline (pInput, line)) {

        if (line != "")
            pOutput << setw (5) << left << line_no++ << " ";
        else
            pOutput << setw (6) << left << " ";
        
        pOutput << line << endl;
    }

    return true;
}
