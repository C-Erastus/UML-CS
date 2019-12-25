#include <fstream>
#include <string> 
#include <iostream> 
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/System.hpp> 
#include <fstream>

// Making the size of the window constant
const int window_height = 1000;
const int window_width = 1000;

class Body : public sf::Drawable{
private: 
    double position_X, position_Y;
    double velocity_X, velocity_Y; 
    double  _mass; 
    double radius; 
    std::string _filename;  /* THE IMAGE */

    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;

    /* Override Draw method */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 

public:

    Body(); // constructor that initialize no prememters
    Body(double pos_X, double pos_Y, double vel_X, double vel_Y, double mass, std::string file_name ); // Use for the manual parts

    void setRadius(double Radius);
    double getRadius(); /* Later found out that this isn't needed */

    /* FUNCTION TO OVERLOAD THE STREAM INPUT OPERATOR >> */
    friend std::istream &operator>>(std::istream &input, Body &tmp);
    
};
