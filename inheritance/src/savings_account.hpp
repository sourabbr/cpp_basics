#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "common.h"
#include "account.hpp"

class SavingsAccount : public Account {

    public:

        SavingsAccount ();
        SavingsAccount (String pName, Double pBalance, Double pRate);

        Bool Deposit (Double pAmount);  

        Double uRate;

    private:

        static constexpr CStrPtr svDefSavingsAccName = "Unnamed savings account";
        static constexpr CDouble svDefSavingsBalance = 0;
        static constexpr CDouble svDefRate           = 5;   
};

#endif