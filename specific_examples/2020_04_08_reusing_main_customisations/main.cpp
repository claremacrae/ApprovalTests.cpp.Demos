#define APPROVALS_CATCH
#include "ApprovalTests.hpp"

using namespace ApprovalTests;

// Put output files in a sub-directory
auto subDirectoryDisposer = Approvals::useApprovalsSubdirectory("approval_tests");

// And put approved and received files in parallel directories
auto defaultNamerDisposer =
    SeparateApprovedAndReceivedDirectoriesNamer::useAsDefaultNamer();
