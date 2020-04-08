# Demo code for reusing customisations 

It's common when using Approval Tests in C++ to add one more more customisations to your `main()` function, perhaps to control the location of approved and received files, or to register a custom comparator.

If you divide your tests across multiple different executables, and use Approval Tests in more than one of those executables, it can be tedious and error-prone to keep the behaviour consistent.

This directory shows one way of ensuring consistency in all your test `main()` functions.

How it works:

* [OurApprovalTestCustomisations.h](OurApprovalTestCustomisations.h)
* [main.cpp](main.cpp)

*[Clare Macrae](https://claremacrae.co.uk/consulting/hire_me.html), 2020-04-08*

