#ifndef APPROVALTESTS_CPP_OURAPPROVALTESTCUSTOMISATIONS_H
#define APPROVALTESTS_CPP_OURAPPROVALTESTCUSTOMISATIONS_H

// The constructor of this class sets up one or more Approval Tests.
// By storing the returned "disposer" (RAII) objects as data members,
// the customisations remain in effect until the object is destroyed.
//
// This is useful if you have multiple test programs, and you want consistent
// customisations in all of them. You can put a class like this in a library
// of code that is shared between all the test programs, and have one of
// these objects created in the main.cpp of each test.
//
// Then, if you later wish to add change or add a customisation, you only
// need to update this one class.
class OurApprovalTestCustomisations
{
public:
    OurApprovalTestCustomisations()
        : subDirectoryDisposer(
              ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests"))
        , defaultNamerDisposer(
              ApprovalTests::SeparateApprovedAndReceivedDirectoriesNamer::useAsDefaultNamer())
    {
    }

private:
    ApprovalTests::SubdirectoryDisposer subDirectoryDisposer;
    ApprovalTests::DefaultNamerDisposer defaultNamerDisposer;

private:
};

#endif //APPROVALTESTS_CPP_OURAPPROVALTESTCUSTOMISATIONS_H
