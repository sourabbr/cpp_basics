#ifndef TRUST_ACCOUNT_HPP
#define TRUST_ACCOUNT_HPP

#include "common.h"
#include "savings_account.hpp"

class TrustAccount : public SavingsAccount {

    public:

        TrustAccount ();
        TrustAccount (String pName, Double pBalance, Double pRate);

        Bool Deposit (Double pAmount);
        Bool Withdraw (Double pAmount);

        UShort uWithdrawLimit;

    private:

        static constexpr const Double svBonus         = 50;
        static constexpr const UShort svWithdrawLimit = 3;
        static constexpr const UShort svPercentLimit  = 20;
};

#endif