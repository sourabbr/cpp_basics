#include "common.h"

Bool IsPalindrome (const String &pStr);

Int main ()
{
    std::Vector<String> test_strings {"a", "aa", "aba", "abbcbba", "ab", "abc",
    "radar", "bob", "ana", "avid diva", "Amore, Roma", "A Toyota's toyota", "A Santa at NASA", "C++"};

    cout << std::boolalpha;
    cout << std::setw (20) << std::left << "Result" << "String" << endl;
    cout << endl;

    for (const auto &s:test_strings)
        cout << std::setw (20) << std::left << s << IsPalindrome (s) << endl;

    cout << endl;

    return 0;
}

Bool IsPalindrome (const String &pStr)
{
    std::stack <Char, deque <Char>> s;
    std::queue <Char, deque <Char>> q;
    Char c1, c2;

    for (const Char c:pStr) {

        if (std::isalpha (c)) {
            
            s.push (c);
            q.push (c);
        }
    }

    while (s.size () > 1) {

        c1 = s.top ();
        c2 = q.front ();

        s.pop ();
        q.pop ();

        if (c1 != c2)
            return false;
    }

    return true;
}