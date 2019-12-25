#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include "PTree.hpp"

int main(int arc, char** argv){
	
	int L, N; 

	/* TAKE TWO INTEGER COMMAND-LINE ARGUMENTS L and N:*/
	// L ---> size of the base square 
	// N ---> the depth of the recursion
	base = atoi(argv[1]);
	recursion = atoi(argv[2]);

	const unsigned width = (6 * L);
	const unsigned height = (4 * L);

	sf::RenderWindow window(sf::VideoMode(width, height), "Pythagoras Tree");
	window.setFramerateLimit(60); 
	while(window.isOpen()){
		sf::Event event; 
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		// call the recursive funciton; 
		window.display();
	}



	return 0;
}
