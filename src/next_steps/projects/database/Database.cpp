#include "Database.h"
#include <unordered_map>
#include <list>

std::unordered_map<std::string, Composer> composers;

Database::Database() {}
Database::~Database(){}

void printList(std::list<Composer>);

// Add a new composer using operations in the Composer class.
// For convenience, we return a reference (pointer) to the new record.
Composer& Database::AddComposer(std::string in_first_name, std::string in_last_name, std::string in_genre, int in_yob, std::string in_fact) {
    Composer composer;
    composer.set_first_name(in_first_name);
    composer.set_last_name(in_last_name);
    composer.set_composer_genre(in_genre);
    composer.set_composer_yob(in_yob);
    composer.set_fact(in_fact);
    composer.set_ranking(0);

    composers[composer.last_name()] = composer;

    return composers[composer.last_name()];
}
// Search for a composer based on last name. Return a reference to the
// found record.
Composer& Database::GetComposer(std::string in_last_name) {
    return composers[in_last_name];
}
// Display all composers in the database.
void Database::DisplayAll(){
    std::unordered_map<std::string, Composer>::iterator it = composers.begin();
    while(it != composers.end()) {
        it->second.Display();
        std::cout << std::endl;
        it++;
    }
}
// Sort database records by rank and then display all.
void Database::DisplayByRank() {
    std::list<Composer> list;
    std::unordered_map<std::string, Composer>::iterator it = composers.begin();

    while(it != composers.end()) {
        list.push_back(it->second);
        it++;
    }

    list.sort([](Composer &f, Composer &s) { return f.ranking() < s.ranking(); });
    printList(list);
}

void printList(std::list<Composer> list) {
    std::list<Composer>::iterator lit = list.begin();
    while(lit != list.end()) {
        lit->Display();
        std::cout << std::endl;
        lit++;
    }
}