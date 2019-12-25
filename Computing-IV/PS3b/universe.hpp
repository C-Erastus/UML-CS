#include <fstream> 
#include <string> 
#include <iostream> 
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <SFML/System.hpp> 
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>

// Making the size of the window constant
const int window_height = 1000;
const int window_width = 1000; 

const double gravitional_const = 6.67e-11;

/* ALL MY TYPDEFS */
//typedef std::pair<std:::vector<int>, double> entities; 

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

    /* variables need for ps1b */ 
    std::vector<Body> Bodies; // stores all the incoming body
    double acceleration_x; 
    double acceleration_y; 
    double for_x; 
    double for_y; 

    std::vector<std::vector<std::pair<std::vector<int>, double > > > Univers_vector;  

    /* Override Draw method */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 

public:

    Body(); // constructor that initialize no prememters
    Body(double pos_X, double pos_Y, double vel_X, double vel_Y, double mass, std::string file_name ); // Use for the manual parts

    void setRadius(double Radius);
    double getRadius(); /* Later found out that this isn't needed */

    /* FUNCTION TO OVERLOAD THE STREAM INPUT OPERATOR >> */
    friend std::istream &operator>>(std::istream &input, Body &tmp);

    /* MUTTATROS SO THAT THE PHYSICS SIMULATION CAN MODIF THE VELOCITITES OF EACH OBJECT */
    void set_x_velocity( double x_velocity );
    void set_y_velocity( double y_velocity );

    double get_x_velocity();
    double get_y_velocity();

    /****** PS2B STARTS HERE ******/

    /* moves the Body object given its internal velocity for that much time */
    void step( double time );

    /* A set function for body */
    void setBodies( std::vector<Body> tmp);

    std::vector<Body> getBodies();

    friend double calculate_radius( Body &body1, Body &body2 );

    friend double calculate_force( double _radius, Body &body1, Body &body2);

    friend double calculate_forceX( double force, double radius, Body &body1, Body &body2);
    friend double calculate_forceY( double force, double radius, Body &body1, Body &body2 );

    void setForces(double Fx, double Fy );

    void displaySize();

    void setPosition();

};
