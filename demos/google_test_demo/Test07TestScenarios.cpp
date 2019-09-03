#include <ostream>
#include "ApprovalTests.hpp"
#include <gtest/gtest.h>
#include <chrono>
#include <ctime>
#include <regex>

using namespace ApprovalTests;

namespace
{
    class LegacyThing;
    std::ostream &operator<<(std::ostream &os, const LegacyThing &result);
    LegacyThing doLegacyOperation();

    class LegacyThing
    {
    };

    std::ostream &operator<<(std::ostream &os, const LegacyThing &result)
    {
        os << "Some complicated output\nfrom my legacy code\n";
        return os;
    }

    LegacyThing doLegacyOperation()
    {
        return LegacyThing();
    }
}

TEST(Test07TestScenarios, New_test_of_legacy_feature)
{
    // Wrap up your legacy feature that needs testing in a function call
    // that returns some state that can be written to a text file
    const LegacyThing result = doLegacyOperation();
    Approvals::verify(result);
}

//--------------------------------------------------------------------------------

// Problem: Output contains data that changes each run, e.g. date-and-time

namespace
{
    long fibonacci(unsigned n)
    {
        if (n < 2) return n;
        return fibonacci(n-1) + fibonacci(n-2);
    }

    // todo make this in to a function that takes a value
    class FibonacciCalculator
    {
    public:
        void calculate(std::string path)
        {
            std::ofstream stream(path);

            stream << "f(42) = " << fibonacci(42) << '\n';
            auto end = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);

            stream << "finished computation at " << std::ctime(&end_time) << '\n';
        }
    };



    class DateRemovingLogFileWriter : public ApprovalWriter
    {
    public:
        explicit DateRemovingLogFileWriter(FibonacciCalculator& calculator) : calculator(calculator)
        {
        }
        std::string getFileExtensionWithDot() const override
        {
            return ".log";
        }

        void write(std::string path) const override
        {
            calculator.calculate(path);
            rewriteLogFileRemovingDatesAndTimes(path);
        }

        void cleanUpReceived(std::string receivedPath) const override
        {
            ::remove(receivedPath.c_str());
        }

    private:
        void rewriteLogFileRemovingDatesAndTimes(const std::string& path) const
        {
            auto lines = readLines(path);
            stripDatesAndTimes(lines);
            writeLines(lines, path);
        }

        std::vector<std::string> readLines(const std::string& path ) const
        {
            std::ifstream infile(path);
            if( !infile.is_open() )
                throw std::domain_error( "Unable to load input file: " + path );

            std::vector<std::string> lines;
            std::string line;
            while (std::getline(infile, line))
            {
                lines.emplace_back(line);
            }
            return lines;
        }

        std::string stripDateAndTime(const std::string& line) const
        {
            // Example date:
            // Tue Sep  3 16:58:52 2019
            const auto dateRegex = R"(([A-Za-z]{3}) ([A-Za-z]{3}) ([0-9 ]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2}) ([0-9]{4}))";
            const std::string replacementText = "[date-time-removed]";
            return std::regex_replace(line, std::regex(dateRegex), replacementText);
        }

        void stripDatesAndTimes(std::vector<std::string>& lines) const
        {
            for(auto& line : lines)
            {
                line = stripDateAndTime(line);
            }
        }

        void writeLines(const std::vector<std::string>& lines, const std::string& path ) const
        {
            std::ofstream outfile(path);
            if( !outfile.is_open() )
                throw std::domain_error( "Unable to re-write input file: " + path );

            for( const auto& line : lines)
            {
                outfile << line << '\n';
            }
        }

    private:
        FibonacciCalculator& calculator;
    };
}

TEST(Test07TestScenarios, Deal_with_dates_and_times_in_output)
{
    // Could refactor the system being tested to allow use of fixed dates and times
    // but that risks breaking the system before you have tests. It would be
    // a useful later step.

    // Or could write a custom diff mechanism that recognises dates and times,
    // and ignores differences in them. Non-trivial.

    // Instead we will post-process our log files when running in test, and
    // strip out any dates and times, so that the files are expected to be
    // identical.

    FibonacciCalculator calculator;
    DateRemovingLogFileWriter datelessWriter(calculator);

    Approvals::verify(datelessWriter);
}

//--------------------------------------------------------------------------------

// Problem: Output is not suitable for writing to a text file

namespace
{
    // Simulation for a Qt's class for representing images:
    class QImage
    {
    public:
        bool save(std::string path) const
        {
            // Glossing over detail that the real QImage save method takes a QString
            return true;
        }
    };

    // An implementation of Approval's ApprovalWriter class, that takes
    // an image, and when needed, writes it out as a correctly-named .png file.
    class QImageWriter : public ApprovalWriter
    {
    public:
        explicit QImageWriter(const QImage& image) : image(image)
        {
        }

        std::string getFileExtensionWithDot() const override
        {
            return ".png";
        }

        void write(std::string path) const override
        {
            image.save(path);
        }

        void cleanUpReceived(std::string receivedPath) const override
        {
        }

    private:
        QImage image;
    };

    QImage getImage()
    {
        return QImage();
    }
}

TEST(Test07TestScenarios, DISABLED_DUE_TO_INTENTIONAL_FAILURE_Test_an_image)
{
    // Approvals is based on saving text files

    // If we are testing a non-text type, we have some options.
    // 1. We could write a text representation of the image, e.g. in pseudo-code
    //      for each pixel:
    //          write xpos, ypos, redvalue, greenvalue, bluevalue
    //    This would work, but if we get a test failure, it would be hard for a user
    //    to interpret the results/
    // 2. We could write the image in a standard graphics format, and if we
    //    have a diffing tool that supports images, the results will be easy to 
    //    interpret.

    QImage image = getImage();
    QImageWriter imageWriter(image);

    ApprovalTestNamer namer;

    // We're using QuietReporter here due to using dummy image-writing code.
    // In a real-world case, we'd use the standard DiffReporter(), to 
    // review the results interactively.
    FileApprover::verify(namer, imageWriter, QuietReporter());
}

//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------
//--------------------------------------------------------------------------------

