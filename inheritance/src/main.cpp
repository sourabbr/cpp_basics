#include "common.h"
#include "account.hpp"
#include "savings_account.hpp"
#include "check_account.hpp"
#include "trust_account.hpp"

void Display (Vector <Account> &pAccount);
void Deposit (Vector <Account> &pAccount, Double pAmount);
void Withdraw (Vector <Account> &pAccount, Double pAmount);

void Display (Vector <SavingsAccount> &pAccount);
void Deposit (Vector <SavingsAccount> &pAccount, Double pAmount);
void Withdraw (Vector <SavingsAccount> &pAccount, Double pAmount);

void Display (Vector <CheckAccount> &pAccount);
void Deposit (Vector <CheckAccount> &pAccount, Double pAmount);
void Withdraw (Vector <CheckAccount> &pAccount, Double pAmount);

void Display (Vector <TrustAccount> &pAccount);
void Deposit (Vector <TrustAccount> &pAccount, Double pAmount);
void Withdraw (Vector <TrustAccount> &pAccount, Double pAmount);

int main ()
{
    Vector <Account> acc;
    Vector <SavingsAccount> sav_acc;
    Vector <CheckAccount> check_acc;
    Vector <TrustAccount> trust_acc;

    acc.push_back (Account ());
    acc.push_back (Account ("Sourab", 150.0));

    Display (acc);
    Deposit (acc, 162);
    Withdraw (acc, 12);
    Display (acc);

    sav_acc.push_back (SavingsAccount ());
    sav_acc.push_back (SavingsAccount ("Sachin", 500.0, 10));

    Display (sav_acc);
    Deposit (sav_acc, 512);
    Withdraw (sav_acc, 120);
    Display (sav_acc);

    check_acc.push_back (CheckAccount ());
    check_acc.push_back (CheckAccount ("Ravi", 1000));

    Display (check_acc);
    Deposit (check_acc, 512);
    Withdraw (check_acc, 120);
    Display (check_acc);

    trust_acc.push_back (TrustAccount ());
    trust_acc.push_back (TrustAccount ("Suma", 2000, 20));

    Display (trust_acc);
    Deposit (trust_acc, 512);
    Withdraw (trust_acc, 120);
    Withdraw (trust_acc, 120);
    Withdraw (trust_acc, 120);
    Withdraw (trust_acc, 120);
    Display (trust_acc);

    return 0;
}

void Display (Vector <Account> &pAccount)
{
    for (auto &acc:pAccount)
        acc.DisplayAccount ();
}

void Deposit (Vector <Account> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Deposit (pAmount))
            cout << "Amount deposited: " << pAmount << endl;
        else
            cout << "Unable to deposit the amount!!" << endl;
}

void Withdraw (Vector <Account> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Withdraw (pAmount))
            cout << "Amount withdrawn: " << pAmount << endl;
        else
            cout << "Unable to withdraw the amount!!" << endl;
}

void Display (Vector <SavingsAccount> &pAccount)
{
    for (auto &acc:pAccount)
        acc.DisplayAccount ();
}

void Deposit (Vector <SavingsAccount> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Deposit (pAmount))
            cout << "Amount deposited: " << pAmount << endl;
        else
            cout << "Unable to deposit the amount!!" << endl;
}

void Withdraw (Vector <SavingsAccount> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Withdraw (pAmount))
            cout << "Amount withdrawn: " << pAmount << endl;
        else
            cout << "Unable to withdraw the amount!!" << endl;
}

void Display (Vector <CheckAccount> &pAccount)
{
    for (auto &acc:pAccount)
        acc.DisplayAccount ();
}

void Deposit (Vector <CheckAccount> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Deposit (pAmount))
            cout << "Amount deposited: " << pAmount << endl;
        else
            cout << "Unable to deposit the amount!!" << endl;
}

void Withdraw (Vector <CheckAccount> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Withdraw (pAmount))
            cout << "Amount withdrawn: " << pAmount << endl;
        else
            cout << "Unable to withdraw the amount!!" << endl;
}

void Display (Vector <TrustAccount> &pAccount)
{
    for (auto &acc:pAccount)
        acc.DisplayAccount ();
}

void Deposit (Vector <TrustAccount> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Deposit (pAmount))
            cout << "Amount deposited: " << pAmount << endl;
        else
            cout << "Unable to deposit the amount!!" << endl;
}

void Withdraw (Vector <TrustAccount> &pAccount, Double pAmount)
{
    for (auto &acc:pAccount)
        if (acc.Withdraw (pAmount))
            cout << "Amount withdrawn: " << pAmount << endl;
        else
            cout << "Unable to withdraw the amount!!" << endl;
}