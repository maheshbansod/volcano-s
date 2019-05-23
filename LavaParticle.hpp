#ifndef LAVAPARTICLE_HPP_INCLUDED
#define LAVAPARTICLE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <list>

class LavaParticle : public sf::Drawable, public sf::Transformable {
    sf::Vector2f vel;
    sf::Vector2f pPos;

    float g; //gravity

    sf::CircleShape particle;

    std::list<sf::CircleShape*> trail;

    static const int LIM_VELX = 500;
    static const int LIM_VELY = 1000;
    static const int PSIZE = 7;
    static const int TRAIL_N = 7;

    float ctr1;

public:
    LavaParticle();
    LavaParticle(sf::Vector2f pos);

    void update(float);
    void revert(float);

    void setGravity(float);
    void setPosition(sf::Vector2f);

private:

    void setRandomValues();
    void initVars();

    virtual void draw(sf::RenderTarget &target,sf::RenderStates states) const {
        states.transform *= getTransform();

        /**also add trail maybe**/
        std::list<sf::CircleShape*>::const_iterator it;
        for(it = trail.begin(); it != trail.end(); it++) {
            target.draw(*(*it), states);
        }

        target.draw(particle, states);
    }
};

#endif // LAVAPARTICLE_HPP_INCLUDED
