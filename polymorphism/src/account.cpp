#include "account.hpp"

Account::Account ()
    : uName {svDefAccName}, uBalance {svDefBalance}
{

}

Account::Account (String pName, Double pBalance)
    : uName {pName}, uBalance {pBalance}
{

}

Account::~Account ()
{
    
}