#include <iostream>
#include <cmath>
#include "PTree.hpp"

PTree::PTree(int base,  int recursion /*sf::ConvexShape polygon*/){
    std::cout << "Calling PTree constructor" << std::endl; 
    std::cout << "The base: " << base << std::endl;
    std::cout << "Recursion: " << recursion << std::endl; 
    size = base;
    depth = recursion;
    
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states)const{
    std::cout << "This should draw" << std::endl; 
   // target.draw(poly);
}

void PTree::pTree(){
    
}