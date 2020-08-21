#include "common.h"

class Test {

    public:

        Test ()
            : vData {0}
        {
            cout << "Test constructor" << endl;
        }

        Test (Int pData)
            : vData {pData}
        {
            cout << "Test parameterized constructor" << endl;
        }

        Int GetData () const
        {
            return vData;
        }

    private:

        Int vData;
};

unique_ptr <Vector <shared_ptr <Test>>> Make ();
Void Fill (Vector <shared_ptr <Test>> &pVec, Int pNum);
Void Display (Vector <shared_ptr <Test>> &pVec);

int main ()
{
    unique_ptr <Vector <shared_ptr <Test>>> vec_ptr;
    Int num = 0;
    vec_ptr = Make ();
    cout << "How many data points do you want to enter: ";
    cin >> num;
    cout << endl;
    Fill (*vec_ptr, num);
    Display (*vec_ptr);
    return 0;
}

unique_ptr <Vector <shared_ptr <Test>>> Make ()
{
    unique_ptr <Vector <shared_ptr <Test>>> ptr = make_unique <Vector <shared_ptr <Test>>> ();
    return ptr;
}

Void Fill (Vector <shared_ptr <Test>> &pVec, Int pNum)
{
        Int num;

    for (Int i = 1; i <= pNum; i++) {

        cout << "Entry [" << i << "] :";
        cin >> num;
        cout << endl;
        pVec.push_back (make_shared <Test> (num));
    }
}

Void Display (Vector <shared_ptr <Test>> &pVec)
{
    for (const auto &test:pVec)
        cout << test->GetData () << endl;
}