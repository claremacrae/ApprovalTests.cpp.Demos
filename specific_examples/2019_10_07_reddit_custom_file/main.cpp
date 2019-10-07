#define APPROVALS_CATCH
#include "ApprovalTests.hpp"

using namespace ApprovalTests;

// Put output files in a sub-directory
auto subDirectoryDisposer = Approvals::useApprovalsSubdirectory("approval_tests");

