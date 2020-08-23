#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include "common.h"

class IllegalBalanceException : public exception {

    public:

        IllegalBalanceException () = default;
        ~IllegalBalanceException () = default;

        virtual CStrPtr what () const noexcept;
};

class InsufficientFundsException : public exception {

    public:

        InsufficientFundsException () = default;
        ~InsufficientFundsException () = default;

        virtual CStrPtr what () const noexcept;
};

#endif