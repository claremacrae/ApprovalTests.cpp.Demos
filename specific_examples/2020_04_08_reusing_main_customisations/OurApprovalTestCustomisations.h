#ifndef APPROVALTESTS_CPP_OURAPPROVALTESTCUSTOMISATIONS_H
#define APPROVALTESTS_CPP_OURAPPROVALTESTCUSTOMISATIONS_H

class OurApprovalTestCustomisations
{
public:
    OurApprovalTestCustomisations()
            : subDirectoryDisposer(
            ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests")),
              defaultNamerDisposer(ApprovalTests::
                                   SeparateApprovedAndReceivedDirectoriesNamer::useAsDefaultNamer())
    {
    }

private:
    ApprovalTests::SubdirectoryDisposer subDirectoryDisposer;
    ApprovalTests::DefaultNamerDisposer defaultNamerDisposer;

private:
};

#endif //APPROVALTESTS_CPP_OURAPPROVALTESTCUSTOMISATIONS_H
