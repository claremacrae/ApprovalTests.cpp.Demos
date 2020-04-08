#define APPROVALS_CATCH
#include "ApprovalTests.hpp"
#include "OurApprovalTestCustomisations.h"

using namespace ApprovalTests;

// This object is created before main() starts, and it sets up all the
// Approval Tests customisations that are to be applied to all tests.
OurApprovalTestCustomisations customisations;

// Note that if you have a custom main() function, you can create
// the customisations object inside your main(), before all the tests
// are run.
