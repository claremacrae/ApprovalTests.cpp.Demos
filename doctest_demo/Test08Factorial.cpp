#include "ApprovalTests.hpp"
#include "doctest.h"

#include <numeric>

using namespace ApprovalTests;

int Factorial( int number )
{
    return number <= 1 ? 1      : Factorial( number - 1 ) * number;  // pass
}

TEST_CASE( "Factorials up to 10" )
{
    // Create a container with values 0 ... 10 inclusive
    std::vector<int> inputs(11);
    std::iota(inputs.begin(), inputs.end(), 0);

    // Act on all values in inputs container:
    Approvals::verifyAll("Factorial", inputs,
        [](auto i, auto& os)
        {
            os << i << "! => " << Factorial(i);
        });
}
