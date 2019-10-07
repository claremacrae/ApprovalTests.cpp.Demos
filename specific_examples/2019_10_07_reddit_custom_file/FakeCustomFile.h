#ifndef APPROVALTESTS_CPP_FAKECUSTOMFILE_H
#define APPROVALTESTS_CPP_FAKECUSTOMFILE_H

#include <string>

class custom_file
{
public:
    explicit custom_file(const std::string&);
    std::string size() const;
        
    int header1 = 42;
    std::string header2 = "FOO";
        
};

#endif //APPROVALTESTS_CPP_FAKECUSTOMFILE_H
