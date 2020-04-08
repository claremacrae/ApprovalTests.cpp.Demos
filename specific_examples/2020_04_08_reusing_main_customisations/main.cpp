#define APPROVALS_CATCH
#include "ApprovalTests.hpp"

using namespace ApprovalTests;

class OurApprovalTestCustomisations
{
public:
    OurApprovalTestCustomisations()
        : subDirectoryDisposer(
              Approvals::useApprovalsSubdirectory("approval_tests")),
          defaultNamerDisposer(
              SeparateApprovedAndReceivedDirectoriesNamer::useAsDefaultNamer())
    {
    }

private:
    SubdirectoryDisposer subDirectoryDisposer;
    DefaultNamerDisposer defaultNamerDisposer;

private:
};

OurApprovalTestCustomisations customisations;
