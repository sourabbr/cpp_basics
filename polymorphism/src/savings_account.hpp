#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "common.h"
#include "account.hpp"

class SavingsAccount : public Account {

    public:

        SavingsAccount ();
        SavingsAccount (String pName, Double pBalance, Double pRate);

        virtual ~SavingsAccount ();

        virtual Bool Deposit (Double pAmount) override;  
        virtual Bool Withdraw (Double pAmount) override;
        virtual Void DisplayAccount () override;

        Double uRate;

    private:

        static constexpr CStrPtr svDefSavingsAccName = "Unnamed savings account";
        static constexpr CDouble svDefSavingsBalance = 0;
        static constexpr CDouble svDefRate           = 5;   
};

#endif