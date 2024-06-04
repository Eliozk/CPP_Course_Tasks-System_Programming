// ID - 208762765
// GMAIL - kolanielioz@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

// Return code to indicate the result of the test run
int return_code = -1;

/**
 * @brief Custom reporter to count the number of assertions and provide feedback.
 * 
 * This reporter extends the ConsoleReporter to count the number of assertions
 * and prints the number of passed tests.
 */
struct ReporterCounter : public ConsoleReporter
{
    /**
     * @brief Construct a new Reporter Counter object
     * 
     * @param input_options Context options provided by doctest
     */
    ReporterCounter(const ContextOptions &input_options)
        : ConsoleReporter(input_options) {}

    /**
     * @brief Override the test_run_end function to add custom behavior at the end of the test run.
     * 
     * @param run_stats Statistics of the test run
     */
    void test_run_end(const TestRunStats &run_stats) override
    {
        int num_passed_tests = run_stats.numAsserts - run_stats.numAssertsFailed;
        std::cout << "Tests passed: " << num_passed_tests << std::endl;
        return_code = (run_stats.numAssertsFailed == 0) ? 0 : 1;
    }
};

// Register the custom reporter
REGISTER_REPORTER("counter", 1, ReporterCounter);

/**
 * @brief Main function to run the test context
 * 
 * Sets up the test context, adds the custom reporter, and runs the tests.
 * 
 * @param argc Argument count
 * @param argv Argument values
 * @return int Return code indicating success or failure
 */
int main(int argc, char **argv)
{
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
    return return_code;
}
