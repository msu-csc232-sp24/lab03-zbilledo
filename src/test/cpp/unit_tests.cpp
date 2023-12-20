/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.1
 * @date    2021-09-10
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "csc232.h"

#if EXECUTE_BLOCK
SCENARIO("Capturing standard output in a test", "[capture]")
{
    // This can be an ofstream as well or any other ostream
    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf *sbuf = std::cout.rdbuf();
    // Redirect cout to our stringstream buffer or any other ostream
    std::cout.rdbuf(buffer.rdbuf());

    GIVEN("something to send to standard output")
    {
        std::string message{"Hi there!"};

        WHEN("that object is inserted into the standard output stream")
        {
            std::cout << message << std::endl;

            THEN( "it is captured by this test" )
            {
                REQUIRE(buffer.str() == (message + "\n"));
                std::cout.rdbuf(sbuf);
            }
        }
    }

    GIVEN("a different object to insert into the stream")
    {
        int number{42};

        WHEN("that different object is inserted into the standard output stream")
        {
            std::cout << number;

            THEN("that different object is captured by this test too")
            {
                REQUIRE(buffer.str() == std::string{"42"});
                std::cout.rdbuf(sbuf);
            }
        }
    }
}
#endif

#if FINISHED_PART_1
SCENARIO("Evaluate Code for Task 1", "[task1]") {
    GIVEN("Some pre-conditions") {
        // declare any objects needed to satisfy preconditions

        WHEN("Some stimulus occurs") {
            // invoke said stimulus

            THEN("Validate any post-conditions") {
                REQUIRE(true == true);
            }
        }
    }

    GIVEN("Another set of pre-conditions") {
        // declare objects needed for this different set of preconditions

        WHEN("Some other stimulus occurs") {
            THEN("Validate any new post-conditions") {
                REQUIRE(true == true);
            }
        }
    }
}
#else
SCENARIO("Bootstrap - If you see this, you haven't done anything yet!", "[bootstrap]")
{
    GIVEN("The student just opened this assignment")
    {
        WHEN("They run the tests target")
        {
            THEN("They receive this encouraging message ==> Great job!")
            {
                bool expected{true};
                bool actual{true};
                REQUIRE(expected == actual);
            }
            AND_THEN("They're encouraged to get started ==> Now tackle task 1!");
        }
    }
}
#endif

#if FINISHED_PART_2
SCENARIO("Evaluate Code for Task 2", "[task2]") {
    GIVEN("Some pre-conditions") {
        // declare any objects needed to satisfy preconditions

        WHEN("Some stimulus occurs") {
            // invoke said stimulus

            THEN("Validate any post-conditions") {
                REQUIRE(true == true);
            }
        }
    }

    GIVEN("Another set of pre-conditions") {
        // declare objects needed for this different set of preconditions

        WHEN("Some other stimulus occurs") {
            THEN("Validate any new post-conditions") {
                REQUIRE(true == true);
            }
        }
    }
}
#endif

#if FINISHED_PART_3
SCENARIO("Evaluate Code for Task 3", "[task3]") {
    GIVEN("Some pre-conditions") {
        // declare any objects needed to satisfy preconditions

        WHEN("Some stimulus occurs") {
            // invoke said stimulus

            THEN("Validate any post-conditions") {
                REQUIRE(true == true);
            }
        }
    }

    GIVEN("Another set of pre-conditions") {
        // declare objects needed for this different set of preconditions

        WHEN("Some other stimulus occurs") {
            THEN("Validate any new post-conditions") {
                REQUIRE(true == true);
            }
        }
    }
}
#endif
