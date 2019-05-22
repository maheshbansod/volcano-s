#ifndef VOLCANO_HPP_INCLUDED
#define VOLCANO_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Volcano : public sf::Drawable, public sf::Transformable {

    int width, height;

public:

    Volcano(int, int);

    void update();

    void errupt();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        ;
    }
};

#endif // VOLCANO_HPP_INCLUDED
