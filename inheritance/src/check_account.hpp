#ifndef CHECK_ACCOUNT_HPP
#define CHECK_ACCOUNT_HPP

#include "common.h"
#include "account.hpp"

class CheckAccount : public Account {

    public:

        CheckAccount ();
        CheckAccount (String pName, Double pBalance);

        Bool Withdraw (Double pAmount);

    private:

        static constexpr const Double svFee = 1.50;
};

#endif