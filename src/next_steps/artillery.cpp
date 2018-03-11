#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits>

const std::string kStartMsg = "Welcome to Artillery\n"
    "You are in the middle of a war and being charged by thousands of enemies.\n"
    "You have one cannon, which you can shoot at any angle.\n"
    "You only have 10 cannonballs for this target..\n"
    "Let's begin...\n";

const double kVelocity = 200.0;
const double kGravity = 32.2;
const double kPi = 3.14;

void StartUp() {
    std::cout << kStartMsg;
}

int Fire(double angle) {
    double flight = (2.0 * kVelocity * sin(angle)) / kGravity;
    return (int) round((kVelocity * cos(angle)) * flight);
}

double AimShot() {
    double angle;

    std::cout << "What angle? ";
    if(!(std::cin >> angle) || angle < 0 || angle > 360) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter an value between 0 and 360." << std::endl;
        angle = -1;
    }

    return angle;
}

bool CheckShot(int targetDist, int impact) {
    bool hit;
    if(impact == targetDist) {
        hit = true;
        std::cout << "You hit him!" << std::endl;
    } else {
        std::string msg("");
        if(impact > targetDist) {
            msg += "over";
        } else {
            msg += "under";
        }
        std::cout << "You " << msg << " shot by " << std::abs(targetDist - impact) << std::endl;
    }

    return hit;
}

bool DefendPosition() {
    srand (time(NULL));
    int targetDist = std::rand() % 1000;
    double angle;
    int shots = 0;
    bool hit = false;

    std::cout << "The enemys is " << targetDist << " feet away!" << std::endl;

    do {
        angle = AimShot();
        if(angle >= 0) {
            int impact = Fire((angle * kPi) / 180);
            shots++;
            hit = CheckShot(targetDist, impact);
            if(hit) { 
                std::cout << "It took " << shots << " shots." << std::endl;
            }
        }
        
    } while(shots < 10 && hit != true);
    
    return hit;
}

int main() {
    StartUp();
    int kills = 0;
    char playing;
    do {
        if(DefendPosition()) {
            kills++;
            std::cout << "I see another one, care to shoot again? (y/n) " << std::endl;
            std::cin >> playing;
        } else {
            std::cout << "The enemy overran your position! Game over." << std::endl;
            playing = 'n';
        }
       
    } while (playing != 'n');
    std::cout << "You killed " << kills << " of the enemy." << std::endl;

    return 0;
}
