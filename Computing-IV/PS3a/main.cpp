#include <iostream> 
#include <fstream>
#include  <string> 
#include "universe.hpp"
#include <vector> 

int main(){

    std::string number_of_particles; 
    std::string u_radi; 

    double Univers_radius; 
    int numberOfPlanets; 

    // Get the number of Particles form the file ---> the fist number 
    std::cin >> number_of_particles; 
    std::cin >> u_radi; 

    numberOfPlanets = atoi(number_of_particles.c_str());
    Univers_radius = atof(u_radi.c_str());

    /* CREATE A VECTOR OF BODIES */
    std::vector<Body> BodyVector;  

    // create a loop. Using the numner of planets in the universe, iterate over it can get all the planets in the univers and their correspoinding details
    for (int i = 0; i < numberOfPlanets; i++){

        Body* tmp = new Body(); 

        std::cin >> *tmp; // overload the stream input operator in the class; 

        tmp->setRadius( Univers_radius );

        BodyVector.push_back(*tmp);
    }

    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "The Solar System");

    window.setFramerateLimit(60);

    window.display();

    // window loop 
    while(window.isOpen()){

        //process events
        sf::Event event; 

        while(window.pollEvent(event)){

            //Close window : exit
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        /* ITERATE OVER THE VECTOR OF BODY */ 
        std::vector<Body>::const_iterator it; 

        for(it = BodyVector.begin(); it != BodyVector.end(); it++)

        window.draw(*it);

        window.display();
    }

    return 0; 
}