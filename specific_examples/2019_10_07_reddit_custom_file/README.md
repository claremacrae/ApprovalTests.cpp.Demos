# Demo code for Reddit question

Demo code to help show Approval Tests approach for this Reddit question: [How should I perform a setup in Catch2?](https://old.reddit.com/r/cpp_questions/comments/de5ojy/how_should_i_perform_a_setup_in_catch2/)

* These test files show the evolution of an approach for testing this code with [ApprovalTests.cpp](https://github.com/approvals/ApprovalTests.cpp). See the comments in the files for more information, but briefly:
* [FileHeaderTests-ApprovalTestsV1.cpp](FileHeaderTests-ApprovalTestsV1.cpp):
    * tests using `&operator<<(std::ostream &os, const custom_file& test_file)`
* [FileHeaderTests-ApprovalTestsV2.cpp](FileHeaderTests-ApprovalTestsV2.cpp):
    * shows how to have more flexibility over the format of the approval file
* [FileHeaderTests-ApprovalTestsV3.cpp](FileHeaderTests-ApprovalTestsV3.cpp):
    * hides the testing implementation away in a function `verify_custom_file_headers()`, to make it easy to test multiple files
* The "approved" files written by Approval Tests are in: [approval_tests/](approval_tests/)
* Other files:
    * [FakeCustomFile.h](FakeCustomFile.h) and [FakeCustomFile.cpp](FakeCustomFile.cpp) are fake implementations of the class being tested
    * [FileHeaderTests-Catch.cpp](FileHeaderTests-Catch.cpp) is the test code shown in the question

For more information about ApprovalTests.cpp, see the **[User Guide](https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/README.md#top)** or **[various talks about Approval Tests for C++](https://claremacrae.co.uk/conferences/presentations.html#)**

*[Clare Macrae](https://claremacrae.co.uk/consulting/hire_me.html), 2019-10-07*
