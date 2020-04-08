#include "ApprovalTests.hpp"
#include "OurApprovalTestCustomisations.h"

OurApprovalTestCustomisations::OurApprovalTestCustomisations()
    : subDirectoryDisposer(
          ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests")),
      defaultNamerDisposer(ApprovalTests::
              SeparateApprovedAndReceivedDirectoriesNamer::useAsDefaultNamer())
{
}
