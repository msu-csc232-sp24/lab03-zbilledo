/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2024
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version 1.0.0
 * @date    09/02/2023
 *
 * @copyright Copyright (c) 2023 James R. Daehn
 */

#include "csc232.h"

#if FINISHED_PART_1
using csc232::Dog;
#endif

#if FINISHED_PART_2
using csc232::GreatDaehn;
using csc232::Yorkie;

/**
 * @brief A simple demonstration of polymorphic behavior.
 */
void demo()
{
    Dog* dogs[ ] = { new Yorkie{ "Snickers" }, new GreatDaehn{ "Deeogee" } };
    for (int index{ 0 }; index < 2; ++index)
    {
        std::cout << dogs[ index ]->speak( ) << std::endl;
        dogs[ index ]->sit( );
    }
}
#endif

int main()
{
#if FINISHED_PART_3
    // TOGGLE the above macro to TRUE (in the include/csc232.h header file) to run this code
    // Call the demo method in the space below (but before the #else)
    /* begin cut-me */
    demo();
    /* end cut-me */
#else
    std::cout << "Hello, Main Target!" << std::endl;
    return EXIT_SUCCESS;
#endif
}
