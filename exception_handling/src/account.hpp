#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "common.h"
#include "exceptions.hpp"

class Account {

    public:

        Account ();
        Account (String pName, Double pBalance);

        virtual ~Account ();

        virtual Bool Deposit (Double pAmount) = 0;
        virtual Bool Withdraw (Double pAmount) = 0;
        virtual Void DisplayAccount () = 0;

        String uName;
        Double uBalance;

    private:

        static constexpr CStrPtr svDefAccName = "Unnamed account";
        static constexpr CDouble svDefBalance = 0;
};

#endif