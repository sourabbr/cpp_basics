#ifndef CHECK_ACCOUNT_HPP
#define CHECK_ACCOUNT_HPP

#include "common.h"
#include "account.hpp"

class CheckAccount : public Account {

    public:

        CheckAccount ();
        CheckAccount (String pName, Double pBalance);

        virtual ~CheckAccount ();

        virtual Bool Deposit (Double pAmount) override;  
        virtual Bool Withdraw (Double pAmount) override;
        virtual Void DisplayAccount () override;

    private:

        static constexpr const Double svFee = 1.50;
};

#endif