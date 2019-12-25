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
        /* scale the x and y positions to size of window; */
    position_X = ( position_X / radius ) * (window_height / 2) + 500;

    //std::cout << "NewX: " << new_x << std::endl;

    position_Y = ( position_Y / radius ) * (window_height / 2) + 500; 

    sprite.setPosition(sf::Vector2f(position_X, position_Y));

}
double Body::getRadius(){
    return radius; 
}
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const{

    target.draw(sprite, states);
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

    /*tmpBody.sprite.setPosition(sf::Vector2f(tmpBody.position_X, tmpBody. position_Y));*/

    return input;
}
