#include <SFML/System.hpp>
#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream> 
#include "LFSR.hpp"

int main(int argc, char* argv[]){

    std::string seed;
    int tabB; 

    //read in command lines
    seed = argv[3];
   tabB = atoi(argv[4]);

   // CREATE AND ISTANCE OF THE CLASS
   LFSR l(seed, tabB);

    sf::Image image;
    if(!image.loadFromFile(argv[1])){
        std::cout << "The image failed" << std::endl; 
        return -1; 
    }  

     sf::Image image1; 
    if(!image1.loadFromFile(argv[1])){
        std::cout << "The image1 failed " << std::endl;
    }


    // p is a pixle
    sf::Color p; 

    // CREATE PHOTOGRAPHIC NEGATIVE IMAGE OF UPPER-LEFT 200 px SQUARE
    for(int x = 0; x < 1000; x++){
        for (int y = 0; y < 750; y++){
            p = image1.getPixel(x,y);
            p.r = p.r ^ l.generate(8);
            p.g = p.g ^ l.generate(8);
            p.b = p.b ^ l.generate(8);
            image.setPixel(x, y, p);
         }
    }

    /************** 1 ******************/

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite; 
    sprite.setTexture(texture);

    /************* 2 ******************/

    sf::Texture texture1; 
    texture1.loadFromImage(image1);

    sf::Sprite sprite1;
    sprite1.setTexture(texture1);

    // create the first window
    sf::RenderWindow window1(sf::VideoMode(1000, 750), "SFML Window1");
        /*** May be set the frame rate **/
    window1.setFramerateLimit(60);

    // create the second window
    sf::RenderWindow window2(sf::VideoMode(1000, 750), "SFML Window2");
    window2.setFramerateLimit(60);





    /* WORKING WITH 2 SFML WINDOW ----> EVENT LOOP */
    while (window1.isOpen() && window2.isOpen()){

	//std::cout << "MAN SHALL NOT LIVE BY BREAD ALONE" << std::endl; 
        sf::Event event;
        while (window1.pollEvent(event)){
	//std::cout << "NO MAN HAS THE RIGHT TO BE AN AMATEUR IN THE MATTER OF PHYSICAL TRAINING" << std::endl; 
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)){
	//std::cout << "IT IS A SHAME FOR A MAN TO GROW OLD WITHOUT SEEING THE BEAUTY AND STRENGTH OF WHICH HIS BODY IS CAPABLE" << std::endl;
            if (event.type == sf::Event::Closed)
            window2.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
        window2.clear();
        window2.draw(sprite);
        window2.display();
    }

    if (!image.saveToFile(argv[2])){
        return -1; 
    }
    
    return 0; 
}
