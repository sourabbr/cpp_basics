#include "common.h"
#include "account.hpp"
#include "savings_account.hpp"
#include "check_account.hpp"
#include "trust_account.hpp"

void Display (Vector <Account *> &pAccount);
void Deposit (Vector <Account *> &pAccount, Double pAmount);
void Withdraw (Vector <Account *> &pAccount, Double pAmount);

int main ()
{
    Vector <Account *> acc;

    acc.push_back (new SavingsAccount ());
    acc.push_back (new SavingsAccount ("Sachin", 500.0, 10));

    acc.push_back (new CheckAccount ());
    acc.push_back (new CheckAccount ("Ravi", 1000));

    acc.push_back (new TrustAccount ());
    acc.push_back (new TrustAccount ("Suma", 2000, 20));

    Display (acc);
    Deposit (acc, 512);
    Withdraw (acc, 120);
    Withdraw (acc, 120);
    Withdraw (acc, 120);
    Withdraw (acc, 120);
    Display (acc);

    return 0;
}

void Display (Vector <Account *> &pAccount)
{
    for (auto acc:pAccount)
        acc->DisplayAccount ();
}

void Deposit (Vector <Account *> &pAccount, Double pAmount)
{
    for (auto acc:pAccount)
        if (acc->Deposit (pAmount))
            cout << "Amount deposited: " << pAmount << endl;
        else
            cout << "Unable to deposit the amount!!" << endl;
}

void Withdraw (Vector <Account *> &pAccount, Double pAmount)
{
    for (auto acc:pAccount)
        if (acc->Withdraw (pAmount))
            cout << "Amount withdrawn: " << pAmount << endl;
        else
            cout << "Unable to withdraw the amount!!" << endl;
}
