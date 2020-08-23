#include "exceptions.hpp"

CStrPtr IllegalBalanceException::what () const noexcept
{
    return "Illegal balance exception";
}

CStrPtr InsufficientFundsException::what () const noexcept
{
    return "Insuffiecient balance exception";
}