## Starting State
* CMake Profiles:
    * Debug
        * `-DAPPROVAL_TESTS_DEMOS_ENABLE_CODE_COVERAGE=off`
    * Release
* CMakeLists.txt files
    * Any code-coverage lines commented out
* Any previous coverage results hidden
* Delete `GildedRoseApprovalTests.VerifyCombinations.approved.txt`

## Steps

**Explain Context**

* Emily Bache's Gilded Rose Refactoring Kata
* Wanted to see if I could reproduce the Java code-coverage techniques she shows in [this video](https://www.praqma.com/stories/advanced-testing-refactoring-techniques/)

**Run first, existing test**

* Run the initial test - it fails
* Review BeyondCompare display
* Review GildedRoseApprovalTests.VerifyCombinations.approved.txt

**Try enabling Code Coverage**

* Get "Code coverage is not enabled for given run configuration"

**Enable Code Coverage**

I could follow the CLion instructions to add compiler and linker flags to enable coverage collection - but I'm going to use something which will give me more options later on - `CodeCoverage.cmake` from 

* Check Debug Profile selected
* Show `CMake/CodeCoverage.cmake` - see [github](https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake)
* Uncomment references to `APPROVAL_TESTS_DEMOS_ENABLE_CODE_COVERAGE` in:
    * `CMakeLists.txt`
    * `specific_examples/2019_11_18_fuzzing_gilded_rose/CMakeLists.txt`
* This adds a new target, `2019_11_18_fuzzing_gilded_rose_coverage`, which we will ignore for now

**Adjust CLion Coverage settings**

* Turn on "Replace active suites with the new one"
* Turn off "Activate Coverage View" to avoid keep fighting its layout
    * We can see the coverage of each file in the Project view for now

**Get to 100% Coverage with CLion's coverage**

**Show branch coverage using `CodeCoverage.cmake` lcov report**

**Get to 100% branch coverage**

**Try mutation testing to further improve coverage**
 