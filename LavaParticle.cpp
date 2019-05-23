#include "LavaParticle.hpp"

LavaParticle::LavaParticle() {
    initVars();
    setRandomValues();
}

LavaParticle::LavaParticle(sf::Vector2f pos) {
    initVars();
    setRandomValues();
    setPosition(pos);
}

void LavaParticle::initVars() {
    g = 0.98;
    ctr1 = 0;

    for(int i=0;i<TRAIL_N;i++) {
        sf::CircleShape *cs = new sf::CircleShape();
        trail.push_back(cs);
    }
}

void LavaParticle::setRandomValues() {
    vel.x = -LIM_VELX/2+rand()%LIM_VELX;
    vel.y = -(rand()%LIM_VELY);

    /**random gradient maybe from red to orange***/
    particle.setFillColor(sf::Color(255,0,0));
    int rad = rand()%PSIZE+3;
    particle.setRadius(rad); /**random size  **/

    std::list<sf::CircleShape*>::iterator it;
    int dcol = 10;
    int rad_dec = rad/(trail.size());
    for(it = trail.begin();it != trail.end();it++) {
        (*it)->setFillColor(particle.getFillColor());
        (*it)->setRadius(rad-=rad_dec);
    }
}

void LavaParticle::update(float dt) {
    std::list<sf::CircleShape*>::iterator it = trail.begin();
    float i=0.5;
    float inc = 0.5;
    int incr = rand()%30;
    for( ;it != trail.end();it++) {
        if (ctr1 < i) break;
        (*it)->move(vel.x*dt, vel.y*dt);
        i+=inc;
    }
    ctr1+=dt;

    particle.move(vel.x*dt, vel.y*dt);
    vel.y+=g;
}

void LavaParticle::revert(float dt) {
    vel.y-=g;
    particle.move(-vel.x*dt, -vel.y*dt);
}

void LavaParticle::setGravity(float grav) {
    g = grav;
}

void LavaParticle::setPosition(sf::Vector2f pos) {
    particle.setPosition(pos);
    std::list<sf::CircleShape*>::iterator it = trail.begin();
    while(it != trail.end()) {
        (*it)->setPosition(pos);
        it++;
    }
}
