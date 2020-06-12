#include "ApprovalTests.hpp"
#include <gtest/gtest.h>

#include <numeric>

using namespace ApprovalTests;

int Factorial(int number)
{
    return number <= 1 ? 1 : Factorial(number - 1) * number; // pass
}

TEST(Test08Factorial, FactorialsUpTo10)
{
    // Create a container with values 0 ... 10 inclusive
    std::vector<int> inputs(11);
    std::iota(inputs.begin(), inputs.end(), 0);

    // Act on all values in inputs container:
    Approvals::verifyAll(
        "Factorial", inputs, [](int i, std::ostream& os) {
            os << i << "! => " << Factorial(i);
        });
}
