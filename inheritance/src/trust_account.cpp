#include "trust_account.hpp"

TrustAccount::TrustAccount ()
    : SavingsAccount (), uWithdrawLimit {svWithdrawLimit}
{

}

TrustAccount::TrustAccount (String pName, Double pBalance, Double pRate)
    : SavingsAccount (pName, pBalance, pRate), uWithdrawLimit {svWithdrawLimit}
{

}

Bool TrustAccount::Deposit (Double pAmount)
{
    return SavingsAccount::Deposit (pAmount >= 5000 ? pAmount + svBonus : pAmount);      
}

Bool TrustAccount::Withdraw (Double pAmount)
{
    if (uWithdrawLimit == 0 || 
        pAmount >= (uBalance * (svPercentLimit / 100)))
        return false;

    if (SavingsAccount::Withdraw (pAmount)) {

        uWithdrawLimit--;
        return true;
    }

    return false;
}