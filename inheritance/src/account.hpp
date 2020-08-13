#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "common.h"

class Account {

    public:

        Account ();
        Account (String pName, Double pBalance);

        Bool Deposit (Double pAmount);
        Bool Withdraw (Double pAmount);
        Void DisplayAccount ();

        String uName;
        Double uBalance;

    private:

        static constexpr CStrPtr svDefAccName = "Unnamed account";
        static constexpr CDouble svDefBalance = 0;
};

#endif