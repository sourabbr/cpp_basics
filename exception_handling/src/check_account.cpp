#include "check_account.hpp"

CheckAccount::CheckAccount ()
    : Account ()
{

}

CheckAccount::CheckAccount (String pName, Double pBalance)
    : Account (pName, pBalance)
{

}

CheckAccount::~CheckAccount ()
{
    
}

Bool CheckAccount::Withdraw (Double pAmount)
{
    if (pAmount < 0)
        return false;

    if ((uBalance - pAmount * (svFee / 100)) < 0)
        return false;

    uBalance -= (pAmount * (svFee / 100));

    if (uBalance - pAmount < 0)
        return false;

    uBalance -= pAmount;

    return true;        
}

Bool CheckAccount::Deposit (Double pAmount)
{
    if (pAmount < 0)
        return false;

    uBalance += pAmount;

    return true;
}

Void CheckAccount::DisplayAccount ()
{
    cout << "Check Account" << endl;
    cout << "Name: " << uName << endl;
    cout << "Balance: " << uBalance << endl;
}