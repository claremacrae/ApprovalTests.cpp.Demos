#include "FakeCustomFile.h"

custom_file::custom_file(const std::string&)
{
    // Ignore filename for now - just use hard-coded values for testing
}

std::string custom_file::size() const
{
    return "100MB";
}
