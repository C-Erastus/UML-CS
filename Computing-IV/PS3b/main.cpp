#include <iostream> 
#include <fstream>
#include  <string> 
#include "universe.hpp"
#include <vector> 
#include <SFML/Audio.hpp>

int main( int argc, char** argv){

    std::string number_of_particles; 
    std::string u_radi; 

    double Univers_radius; 
    int numberOfPlanets; 

    /**** PS2B VARIABLES ****/
    double time = 0; 
    double change_in_time = 0;

    //Body Nbody();
    Body *tmp;

    change_in_time = atof(argv[1]);
    time = atof(argv[2]);

    // Get the number of Particles form the file ---> the fist number 
    std::cin >> number_of_particles; 
    std::cin >> u_radi; 

    numberOfPlanets = atoi(number_of_particles.c_str());
    Univers_radius = atof(u_radi.c_str());

    /* CREATE A VECTOR OF BODIES */
    std::vector<Body> BodyVector;  

    // create a loop. Using the numner of planets in the universe, iterate over it can get all the planets in the univers and their correspoinding details
    for (int i = 0; i < numberOfPlanets; i++){

        tmp = new Body(); // allocate space for a new Body object; 

        std::cin >> *tmp; // overload the stream input operator in the class; 

        tmp->setRadius( Univers_radius );
        tmp->setPosition();
        BodyVector.push_back(*tmp);
    }
    /* CALL A FUNCTION TO SET THE VECTOR OF BODY */

    //tmp->step(time);
    tmp->setBodies( BodyVector );
    tmp->step(time);
    tmp->displaySize();

    sf::RenderWindow window(sf::VideoMode(window_height, window_width), "The Solar System");

    window.setFramerateLimit(60);

    window.display();

    //sf::Music music; 

    /*if(!music.openFromFile("I Am3\:27KamotoUtopian")){
        return -1;
    }*/
   // music.play();

    std::vector<Body>::iterator x, y;
    std::vector<Body>::iterator it; 

    

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

        /* CALCULATE THE NET FORCE OF EACH PLANET */

        int i, j; 
        double radius, force; 
        x = BodyVector.begin();
        double force_x = 0.0; 
        double force_y = 0.0;
   
       

    for ( i = 0; i < numberOfPlanets; i++){

        y = BodyVector.begin();
        force_x = 0;
        force_y = 0;
        
        // create a vector that holds a piar that holds a vector of int & a double

        for ( j = 0; j < numberOfPlanets; j ++){
            
            if ( i != j){


                // calculate the radius of the two entities at i & j
                radius = calculate_radius( *x, *y );

                // calculate the force of the two entities at i & j;
                force = calculate_force( radius, *x, *y );
            

            
                //calculate the sume of the all the pairwise forces x & y; 
                force_x += calculate_forceX( force, radius, *x, *y);
                force_y += calculate_forceY( force, radius, *x, *y );
            }   
            y++;
        }

        x->setForces( force_x, force_y);
        x++;
        //Univers_vector.push_back(myVector);
    
    }

        /* ITERATE OVER THE VECTOR OF BODY */ 
   

        for(it = BodyVector.begin(); it != BodyVector.end(); it++){
            window.draw(*it);

            it->step(time);

            // set position
           it->setPosition();
        }

        window.display();
    }

    return 0; 
}