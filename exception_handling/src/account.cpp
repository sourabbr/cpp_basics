#include "account.hpp"

Account::Account ()
    : uName {svDefAccName}, uBalance {svDefBalance}
{
    if (uBalance < 0)
        throw IllegalBalanceException ();
}

Account::Account (String pName, Double pBalance)
    : uName {pName}, uBalance {pBalance}
{
    if (uBalance < 0)
        throw IllegalBalanceException ();
}

Account::~Account ()
{
    
}