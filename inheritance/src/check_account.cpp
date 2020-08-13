#include "check_account.hpp"

CheckAccount::CheckAccount ()
    : Account ()
{

}

CheckAccount::CheckAccount (String pName, Double pBalance)
    : Account (pName, pBalance)
{

}

Bool CheckAccount::Withdraw (Double pAmount)
{
    if (pAmount < 0)
        return false;

    if (Account::Withdraw (pAmount * (svFee / 100)))
        return Account::Withdraw (pAmount);

    return false;        
}