// test_composer.cpp, Maggie Johnson
//
// This program tests the Composer class.

#include <iostream>
#include "Composer.h"

int main()
{
    std::cout << std::endl
         << "Testing the Composer class." << std::endl
         << std::endl;

    Composer composer;

    composer.set_first_name("Ludwig van");
    composer.set_last_name("Beethoven");
    composer.set_composer_yob(1770);
    composer.set_composer_genre("Romantic");
    composer.set_fact("Beethoven was completely deaf during the latter part of "
                      "his life - he never heard a performance of his 9th symphony.");
    composer.Promote(2);
    composer.Demote(1);
    composer.Display();
}