#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"
#include "Meteor.h"

class Gary
{
public:

	Gary(sf::Vector2f position) {

		head.setRadius(13);
		head.setPosition(position);
		neck.setSize({ 26.0,26.0 });
		neck.setPosition({ position.x,position.y + 13 });
		chest.setPointCount(3);
		chest.setRadius(23);
		chest.setPosition({ position.x - 10,position.y + 15 });
		abdomin.setPointCount(3);
		abdomin.setRadius(23);
		abdomin.setPosition({ position.x + 37,position.y + 84 });
		abdomin.setRotation(180.0);
		belt.setSize({ 23.0,7.0 });
		belt.setPosition({ position.x + 2,position.y + 68 });
		ass.setSize({ 23.0,12.0 });
		ass.setPosition({ position.x + 2,position.y + 75 });
		rLeg.setSize({ 6.0,35.0 });
		rLeg.setPosition({ position.x + 19,position.y + 85 });
		lLeg.setSize({ 6.0,35.0 });
		lLeg.setPosition({ position.x + 2,position.y + 85 });
		rBoot.setSize({ 10.0,15.0 });
		rBoot.setPosition({ position.x + 17,position.y + 110 });
		lBoot.setSize({ 10.0,15.0 });
		lBoot.setPosition({ position.x ,position.y + 110 });
		rFoot.setRadius({ 8.0,5.0 });
		rFoot.setPosition({ position.x + 19,position.y + 120 });
		rFoot.setRotation(20.0);
		lFoot.setRadius({ 8.0,5.0 });
		lFoot.setPosition({ position.x - 7,position.y + 125 });
		lFoot.setRotation(-20.0);
		rUtility.setSize({ 6.0,10.0 });
		rUtility.setPosition({ position.x + 7 + 17,position.y + 64 });
		lUtility.setSize({ 6.0,10.0 });
		lUtility.setPosition({ position.x - 2 ,position.y + 64 });
		rArm1.setSize({ 25.0,6.0 });
		rArm1.setPosition({ position.x + 12 + 17,position.y + 45 });
		rArm1.setRotation(-15.0);
		rArm2.setSize({ 6.0,30.0 });
		rArm2.setPosition({ position.x + 45,position.y + 15 });
		rArm2.setRotation(-7.0);
		rArm3.setSize({ 12.0,15.0 });
		rArm3.setPosition({ position.x + 42,position.y + 12 });
		rArm3.setRotation(-7.0);
		lArm.setSize({ 7.0,30.0 });
		lArm.setPosition({ position.x - 5 ,position.y + 45 });
		lArm.setRotation(30.0);
		lHand.setRadius(6);
		lHand.setPosition({ position.x - 25,position.y + 70 });
		cannon.setRadius(6);
		cannon.setPosition({ position.x + 42,position.y + 6 });
		shieldUp = false;
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(head);
		window.draw(neck);
		window.draw(chest);
		window.draw(abdomin);
		window.draw(belt);
		window.draw(ass);
		window.draw(rLeg);
		window.draw(lLeg);
		window.draw(rBoot);
		window.draw(lBoot);
		window.draw(rFoot);
		window.draw(lFoot);
		window.draw(rUtility);
		window.draw(lUtility);
		window.draw(rArm1);
		window.draw(rArm2);
		window.draw(rArm3);
		window.draw(lArm);
		window.draw(lHand);
		window.draw(cannon);
	}

	void move(sf::Vector2f distance) {
		head.move(distance);
		neck.move(distance);
		chest.move(distance);
		abdomin.move(distance);
		belt.move(distance);
		ass.move(distance);
		rLeg.move(distance);
		lLeg.move(distance);
		rBoot.move(distance);
		lBoot.move(distance);
		rFoot.move(distance);
		lFoot.move(distance);
		rUtility.move(distance);
		lUtility.move(distance);
		rArm1.move(distance);
		rArm2.move(distance);
		rArm3.move(distance);
		lArm.move(distance);
		lHand.move(distance);
		cannon.move(distance);
	}

	sf::Vector2f getCannon() {
		return cannon.getPosition();
	}

	boolean isCollidingWithMeteor(Meteor * meteor) {
		if ((head.getGlobalBounds().intersects(meteor->getMeteor().getGlobalBounds())) || (neck.getGlobalBounds().intersects(meteor->getMeteor().getGlobalBounds())) || (chest.getGlobalBounds().intersects(meteor->getMeteor().getGlobalBounds())) || (abdomin.getGlobalBounds().intersects(meteor->getMeteor().getGlobalBounds()))) {
			return true;
		}
		return false;
	}

	void destruct() {
		head.setPosition({ 2000,2000 });
		neck.setPosition({ 2000,2000 });
		chest.setPosition({ 2000,2000 });
		abdomin.setPosition({ 2000,2000 });
		rArm1.setPosition({ 2000,2000 });
		rArm2.setPosition({ 2000,2000 });
		rArm3.setPosition({ 2000,2000 });
		lArm.setPosition({ 2000,2000 });
		lHand.setPosition({ 2000,2000 });
		cannon.setPosition({ 2000,2000 });
	}

	boolean getShieldUp() {
		return shieldUp;
	}

	void setShieldUp(boolean a) {
		shieldUp = a;
	}

	/*boolean isCollidingWithShield(puShield * shield) {
		if ((head.getGlobalBounds().intersects(shield->getMeteor().getGlobalBounds())) || (neck.getGlobalBounds().intersects(shield->getMeteor().getGlobalBounds())) || (chest.getGlobalBounds().intersects(shield->getMeteor().getGlobalBounds())) || (abdomin.getGlobalBounds().intersects(shield->getMeteor().getGlobalBounds()))) {
			return true;
		}
		return false;
	}*/


private:
	sf::CircleShape head;
	sf::RectangleShape neck;
	sf::CircleShape chest;
	sf::CircleShape abdomin;
	sf::RectangleShape belt;
	sf::RectangleShape ass;
	sf::RectangleShape rLeg;
	sf::RectangleShape lLeg;
	sf::RectangleShape rBoot;
	sf::RectangleShape lBoot;
	EllipseShape rFoot;
	EllipseShape lFoot;
	sf::RectangleShape rUtility;
	sf::RectangleShape lUtility;
	sf::RectangleShape rArm1;
	sf::RectangleShape rArm2;
	sf::RectangleShape rArm3;
	sf::RectangleShape lArm;
	sf::CircleShape lHand;
	sf::CircleShape cannon;
	boolean shieldUp;


};

