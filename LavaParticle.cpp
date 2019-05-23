#include "LavaParticle.hpp"

LavaParticle::LavaParticle() {
    setRandomValues();
    initVars();
}

LavaParticle::LavaParticle(sf::Vector2f pos) {
    setRandomValues();
    initVars();
    setPosition(pos);
}

void LavaParticle::initVars() {
    /**random gradient maybe from red to orange***/
    particle.setFillColor(sf::Color());
    particle.setRadius(rand()%30+5); /**random size 5-35 **/

    g = 9.8;
}

void LavaParticle::setRandomValues() {
    vel.x = rand()%LIM_VELX;
    vel.y = rand()%LIM_VELY;
}

void LavaParticle::update(float dt) {
    move(vel.x*dt, (vel.y+g)*dt);
}

void LavaParticle::revert(float dt) {
    move(-vel.x*dt, -(vel.y+g)*dt);
}

void LavaParticle::setGravity(float grav) {
    g = grav;
}
