#ifndef LAVAPARTICLE_HPP_INCLUDED
#define LAVAPARTICLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class LavaParticle : public sf::Drawable, public sf::Transformable {
    sf::Vector2f vel;

    float g; //gravity

    sf::CircleShape particle;

    static const int LIM_VELX = 1000;
    static const int LIM_VELY = 1000;

public:
    LavaParticle();
    LavaParticle(sf::Vector2f pos);

    void update(float);
    void revert(float);

    void setGravity(float);

private:

    void setRandomValues();
    void initVars();

    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) {
        states.transform *= getTransform();

        /**also add trail maybe**/

        target.draw(particle);
    }
};

#endif // LAVAPARTICLE_HPP_INCLUDED
