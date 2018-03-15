#include "Composer.h"
#include <iostream>

Composer::Composer() {}

Composer::~Composer() {}

void Composer::Promote(int increment) {
    ranking_ += increment;
}
void Composer::Demote(int decrement) {
    ranking_ -= decrement;
}

void Composer::Display() {
    std::cout << first_name_ << " " << last_name_ << std::endl;
    std::cout << "Ranking: " << ranking_ << std::endl;
    std::cout << "Born: " << composer_yob_ << std::endl;
    std::cout << "Genre: " << composer_genre_ << std::endl;
    std::cout << fact_ << std::endl; 
}