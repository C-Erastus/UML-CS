#include <SFML/Graphics.hpp>
#include <iostream>

int main(){

	// create the main windo
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window"); 

	window.setFramerateLimit(60);  
	
	//Load a sprite to display
	sf::Texture texture; 
	if (!texture.loadFromFile("sprite.png"))
		return EXIT_FAILURE;
	sf::Sprite sprite(texture);  
	
	while(window.isOpen()){
	// Provess events
	sf::Event event;
	while (window.pollEvent(event)){
		
		// close window: exit
		if (event.type == sf::Event::Closed)
			window.close(); 
		}
	
	//move the sprite
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		sprite.move(-1, 0); 
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		sprite.move(1, 0);// This Works

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		sprite.move(0, -1);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		sprite.move(0, 1); // This works

	//Rotate the image 
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		sprite.rotate(10);  

	// Clear screen
	window.clear(); 

	//Draw the sprite 	
	window.draw(sprite);
	
	std::cout << "Spin that shit" << std::endl; 	
	//update the window
	window.display();  

	}

	return 0;
}

