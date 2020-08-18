#include "savings_account.hpp"

SavingsAccount::SavingsAccount ()
    : Account (svDefSavingsAccName, svDefSavingsBalance), uRate {svDefRate}
{

}

SavingsAccount::SavingsAccount (String pName, Double pBalance, Double pRate)
    : Account (pName, pBalance), uRate {pRate}
{

}

SavingsAccount::~SavingsAccount ()
{
    
}

Bool SavingsAccount::Deposit (Double pAmount)
{
    pAmount += pAmount * (uRate / 100);

    if (pAmount < 0)
        return false;

    uBalance += pAmount;

    return true;
}

Bool SavingsAccount::Withdraw (Double pAmount)
{
    if (uBalance - pAmount < 0)
        return false;

    uBalance -= pAmount;

    return true;
}

Void SavingsAccount::DisplayAccount ()
{
    cout << "Savings Account" << endl;
    cout << "Name: " << uName << endl;
    cout << "Balance: " << uBalance << endl;
    cout << "Rate: " << uRate << endl;
}