#include "LavaParticle.hpp"

LavaParticle::LavaParticle() {
    setRandomValues();
    initCircleShape();
}

LavaParticle(sf::Vector2f pos) {
    setRandomValues();
    initCircleShape();
    setPosition(pos);
}

void LavaParticle::initCirclShape() {
    /**random gradient maybe from red to orange***/
    particle.setFillColor(sf::Color());
    particle.setRadius(rand()%30+5); /**random size 5-35 **/
}

void LavaParticle::setRandomValues() {
    vel.x = rand()%LIM_VELX;
    vel.y = rand()%LIM_VELY;
}
