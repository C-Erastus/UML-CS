

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class PTree : public sf::Drawable{
public:
    PTree(); 

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

    void pTree(); // recursively draw the tree




private: 
    int L; 
    int N;
};


