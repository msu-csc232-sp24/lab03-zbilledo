/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2024
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
using csc232::Dog;

enum DogsIndex
{
    YORKIE, FIRST_GREAT_DAEHN, SECOND_GREAT_DAEHN
};

SCENARIO( "Evaluate Code for Task 1: The Dog interface exists", "[task1]" )
{
    Dog* dogs[] = { nullptr, nullptr, nullptr };

    GIVEN( "A pointer to a Dog" )
    {
        REQUIRE( dogs[ YORKIE ] == nullptr );
        WHEN( "This code compiles" )
        {
            THEN( "No errors are generated." )
            {
                REQUIRE( true );
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
SCENARIO("Evaluate Code for Task 2: Dog Implementations exist", "[task2]") {
    using csc232::Yorkie;
    using csc232::GreatDaehn;

    // This can be an ofstream as well or any other ostream
    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf* sbuf = std::cout.rdbuf( );
    // Redirect cout to our stringstream buffer or any other ostream
    std::cout.rdbuf( buffer.rdbuf( ) );

    const static std::string YORKIE_RESPONSE { "DID YOU SAY SPEAK?" };
    const static std::string GREAT_DAEHN_RESPONSE { "What?" };

    GIVEN( "A a collection of Dog pointers" )
    {
        Dog* dogs[] = { new Yorkie { "snickers" }, new GreatDaehn { "sugar" }, new GreatDaehn { "spice" } };

        WHEN( "I ask a Yorkie to speak" )
        {
            std::string response { dogs[ YORKIE ]->speak( ) };

            THEN( "I expect a loud response" )
            {
                REQUIRE( response == YORKIE_RESPONSE );
                std::cout.rdbuf( sbuf );
            }
        }

        WHEN( "I ask a GreatDaehn to speak" )
        {
            std::string response { dogs[ FIRST_GREAT_DAEHN ]->speak( ) };

            THEN( "I expect a clueless response" )
            {
                REQUIRE( response == GREAT_DAEHN_RESPONSE );
                std::cout.rdbuf( sbuf );
            }
        }

        WHEN( "I as a Yorkie to sit" )
        {
            dogs[ YORKIE ]->sit( );

            THEN( "I expect the Yorkie has been shown to be seated" )
            {
                std::string current_output { buffer.str( ) };
                std::string latest_output { "A Yorkie named snickers just sat down.\n" };
                bool ends_with { csc232::StringEndsWith( current_output, latest_output ) };
                REQUIRE( ends_with );
                std::cout.rdbuf( sbuf );
            }
        }

        WHEN( "I as the first GreatDaehn to sit" )
        {
            dogs[ FIRST_GREAT_DAEHN ]->sit( );

            THEN( "I expect the first GreatDaehn has been shown to be seated" )
            {
                std::string current_output { buffer.str( ) };
                std::string latest_output { "A GreatDaehn named sugar just sat down.\n" };
                bool ends_with { csc232::StringEndsWith( current_output, latest_output ) };
                REQUIRE( ends_with );
                std::cout.rdbuf( sbuf );
            }
        }

        WHEN( "I as the second GreatDaehn to sit" )
        {
            dogs[ SECOND_GREAT_DAEHN ]->sit( );

            THEN( "I expect the second GreatDaehn has been shown to be seated" )
            {
                std::string current_output { buffer.str( ) };
                std::string latest_output { "A GreatDaehn named spice just sat down.\n" };
                bool ends_with { csc232::StringEndsWith( current_output, latest_output ) };
                REQUIRE( ends_with );
                std::cout.rdbuf( sbuf );
            }
        }
    }
}
#endif

#if FINISHED_PART_3
SCENARIO("Evaluate Code for Task 3: Demonstrate Polymorphism", "[task3]") {
    GIVEN( "A collection of Dog pointers" )
    {
        std::vector<csc232::Dog*> dogs { new csc232::Yorkie { "snickers" }, new csc232::GreatDaehn { "sugar" } };

        WHEN( "I compare responses to the same message" )
        {
            std::string yorkie_response { dogs.at( YORKIE )->speak( ) };
            std::string great_daehn_response { dogs.at( FIRST_GREAT_DAEHN )->speak( ) };
            int comparison { yorkie_response.compare( great_daehn_response ) };

            THEN("They're found to be different")
            {
                REQUIRE_FALSE( comparison == 0);
            }
        }
    }
}
#endif
