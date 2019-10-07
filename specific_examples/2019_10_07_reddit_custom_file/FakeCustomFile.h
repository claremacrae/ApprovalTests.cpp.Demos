#ifndef APPROVALTESTS_CPP_FAKECUSTOMFILE_H
#define APPROVALTESTS_CPP_FAKECUSTOMFILE_H

#include <string>

class custom_file
{
public:
    custom_file(const std::string&)
    {
        // Ignore filename for now - just use hard-coded values for testing
    }
    std::string size() const
    {
        return "100MB";
    }
        
    int header1 = 42;
    std::string header2 = "FOO";
        
};

#endif //APPROVALTESTS_CPP_FAKECUSTOMFILE_H
