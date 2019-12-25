#include <iostream> 
#include "universe.hpp"

Body::Body(){
    std::cout << "THIS CONSTRUCT INITIALIZE NO PARAMETER" << std::endl;
}

Body::Body(double pos_X, double pos_Y, double vel_X, double vel_Y, double object_mass, std::string file_name ){
    
    position_X = pos_X; 
    position_Y = pos_Y; 
    velocity_X = vel_X; 
    velocity_Y = vel_Y;

    _mass = object_mass; 
    _filename = file_name; 

     //Load image into object 
    if(!image.loadFromFile(file_name)){

        std::cout << "Failed to LAOD IMAGE" << std::endl; 

        return; // the file does not exist
    }

    /* load the image into a texture */
    texture.loadFromImage(image);

    /* load the texture into a sprite */
    sprite.setTexture(texture);


    sprite.setPosition(sf::Vector2f(position_X, position_Y));
}

void Body::setRadius(double Radi){

    radius = Radi; 

}
double Body::getRadius(){
    return radius; 
}
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const{
 
    target.draw(sprite);
}

std::istream &operator>>(std::istream &input, Body &tmpBody){

    input >> tmpBody.position_X >> tmpBody.position_Y;
    input >> tmpBody.velocity_X >> tmpBody.velocity_Y;
    input >> tmpBody._mass >> tmpBody._filename; 

    /* CHECK IF THE FILE EXISTS */ 
    if( !tmpBody.image.loadFromFile(tmpBody._filename)){
        std::cout << "Hello C. Erastus, This file doesn't exist" << std::endl; 
        return input; // Quit if the file doesn't exitst 
    }

    tmpBody.texture.loadFromImage(tmpBody.image);

    tmpBody.sprite.setTexture(tmpBody.texture);

    tmpBody.sprite.setPosition(sf::Vector2f(tmpBody.position_X, tmpBody. position_Y));

    tmpBody.for_x = 0;
    tmpBody.for_y = 0;
    tmpBody.acceleration_x = 0;
    tmpBody.acceleration_y = 0;

    return input;
}
    /**************************PS3B STARTS HERE *********************************/

void Body::setBodies( std::vector<Body> tmp){
    Bodies = tmp; 
}
std::vector<Body> Body::getBodies(){
    return Bodies;
}
void Body::step( double time ){

    /* CALCUALTE THE ACCELERATTIONS */
    acceleration_x = (for_x / _mass);

    acceleration_y = (for_y / _mass);

    /* CALCULATE THE NEW VELOCITIES */
    velocity_X = velocity_X + ( time * acceleration_x);
    velocity_Y = velocity_Y + ( time * acceleration_y);

    /* CALCULATE THE NEW POSITIONS */
    position_X = position_X + (time * velocity_X);
    position_Y = position_Y + (time * velocity_Y);

}

 double calculate_radius( Body &body1, Body &body2 ){

     double radius; 

     double dx = body2.position_X - body1.position_X;
     double dy = body2.position_Y - body1.position_Y; 
     double tmp = pow(dx, 2) + pow(dy, 2);

     radius = sqrt(tmp);

     //std::cout << radius << std::endl; 

     return radius;

 }
double calculate_force( double _radius, Body &body1, Body &body2 ){

    double force;

    double tmp = (body1._mass * body2._mass) / (_radius * _radius );

    force = gravitional_const * tmp;

    return force; 
}
double calculate_forceX( double force, double radius, Body &body1, Body &body2 ){

    double dx = body2.position_X - body1.position_X;

    double Fx = force * (dx/radius);

    return Fx; 

}
double calculate_forceY( double force, double radius, Body &body1, Body &body2 ){

    double dy = body2.position_Y - body1.position_Y; 

    double Fy = force * (dy/radius);

    return Fy;

}
void Body::setForces(double Fx, double Fy ){

    for_x = Fx; 
    for_y = Fy; 

    }
void Body::displaySize(){

    std::cout << "Size of vector: " << Bodies.size() << std::endl;
    std::cout << "Size of Universe: " << Univers_vector.size() << std::endl; 
}
void Body::setPosition(){
    
    double pos_x = ( position_X / radius ) * (window_height / 2) + 500;
    double pos_y = ( position_Y / radius ) * (window_height / 2) + 500; 

    sprite.setPosition(sf::Vector2f(pos_x, pos_y));

}