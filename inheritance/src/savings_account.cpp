#include "savings_account.hpp"

SavingsAccount::SavingsAccount ()
    : Account (svDefSavingsAccName, svDefSavingsBalance), uRate {svDefRate}
{

}

SavingsAccount::SavingsAccount (String pName, Double pBalance, Double pRate)
    : Account (pName, pBalance), uRate {pRate}
{

}

Bool SavingsAccount::Deposit (Double pAmount)
{
    pAmount += pAmount * (uRate / 100);

    return Account::Deposit (pAmount);
}