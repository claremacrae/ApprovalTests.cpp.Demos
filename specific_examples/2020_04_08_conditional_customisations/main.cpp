#define APPROVALS_CATCH_EXISTING_MAIN
#include "ApprovalTests.hpp"

// ApprovalTests uses Disposers, or RAII objects, to support customisations
// of fixed scope. When the returned object goes out of scope, the customisation
// us reversed.
//
// I was recently asked how to use this feature for a customisation that
// should be optionally enabled. Creating the customisation inside an
// 'if' block doesn't work, as the closing of the if block reverts
// the change.
//
// Here is one way of doing it, by holding on to the RAII object in a
// shared_ptr or unique_ptr that is outside the scope of the if block.

// A struct or class to create, and hold on to, the RAII object.
struct ReporterRAIIHolder
{
    explicit ReporterRAIIHolder(ApprovalTests::Reporter* reporter)
        : disposer_(ApprovalTests::Approvals::useAsDefaultReporter(
              std::unique_ptr<ApprovalTests::Reporter>(reporter)))
    {
    }
    ApprovalTests::DefaultReporterDisposer disposer_;
};

using ReporterRAIIHolderPtr = std::unique_ptr<ReporterRAIIHolder>;

int main(int argc, char* argv[])
{
    ReporterRAIIHolderPtr reporter_holder;
    if (true) // replace with your own conditional
    {
        reporter_holder = std::make_unique<ReporterRAIIHolder>(
            new ApprovalTests::Mac::BeyondCompareReporter);
    }

    return Catch::Session().run(argc, argv);
}
