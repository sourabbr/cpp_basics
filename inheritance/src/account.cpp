#include "account.hpp"

Account::Account ()
    : uName {svDefAccName}, uBalance {svDefBalance}
{

}

Account::Account (String pName, Double pBalance)
    : uName {pName}, uBalance {pBalance}
{

}

Bool Account::Deposit (Double pAmount)
{
    if (pAmount < 0)
        return false;

    uBalance += pAmount;

    return true;
}

Bool Account::Withdraw (Double pAmount)
{
    if (uBalance - pAmount < 0)
        return false;

    uBalance -= pAmount;

    return true;
}

Void Account::DisplayAccount ()
{
    cout << "Name: " << uName << endl;
    cout << "Balance: " << uBalance << endl;
}