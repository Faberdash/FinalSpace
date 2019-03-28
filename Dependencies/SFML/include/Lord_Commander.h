#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "EllipseShape.h"

class Lord_Commander
{
public:
	Lord_Commander(sf::Vector2f position) {

		head.setRadius({ 37.0,30.0 });
		head.setPosition({ position.x + 3, position.y });
		head.setFillColor(sf::Color::Blue);
		rEye.setRadius(8);
		rEye.setPosition({ position.x + 53 , position.y + 18 });
		rEye.setFillColor(sf::Color::Yellow);
		lEye.setRadius(8);
		lEye.setPosition({ position.x + 13, position.y + 18 });
		lEye.setFillColor(sf::Color::Yellow);
		mouth.setRadius({ 15.0,8.0 });
		mouth.setPosition({ position.x + 25,position.y + 35 });
		neck.setSize({ 30.0,8.0 });
		neck.setPosition({ position.x + 25 ,position.y + 58 });
		body.setPointCount(4);
		body.setPoint(0, { position.x + 55, position.y + 65 });
		body.setPoint(1, { position.x + 25, position.y + 65 });
		body.setPoint(2, { position.x + 10, position.y + 130 });
		body.setPoint(3, { position.x + 70, position.y + 130 });
		rHand.setRadius({ 10.0,6.0 });
		rHand.setPosition({ position.x + 78, position.y + 83 });
		rHand.setRotation(20);
		rHand.setFillColor(sf::Color::Blue);
		rGauntlet.setRadius({ 10.0,7.0 });
		rGauntlet.setPosition({ position.x + 70, position.y + 73 });
		rGauntlet.setFillColor(sf::Color::Green);
		rGauntlet.setRotation(23);
		rJewel.setRadius({ 7.0,4.0 });
		rJewel.setPosition({ position.x + 73, position.y + 75 });
		rJewel.setFillColor(sf::Color::Red);
		rJewel.setRotation(23);
		lHand.setRadius({ 10.0,6.0 });
		lHand.setPosition({ position.x - 24, position.y + 94 });
		lHand.setRotation(-20);
		lHand.setFillColor(sf::Color::Blue);
		rArm.setSize({ 50.0,15.0 });
		rArm.setPosition({ position.x + 50,position.y + 58 });
		rArm.setRotation(35);
		lArm.setSize({ 50.0,15.0 });
		lArm.setPosition({ position.x - 15,position.y + 89 });
		lArm.setRotation(-35);
		lGauntlet.setRadius({ 10.0,7.0 });
		lGauntlet.setPosition({ position.x - 15, position.y + 82 });
		lGauntlet.setFillColor(sf::Color::Green);
		lGauntlet.setRotation(-20);
		lJewel.setRadius({ 7.0,4.0 });
		lJewel.setPosition({ position.x - 12, position.y + 82 });
		lJewel.setFillColor(sf::Color::Red);
		lJewel.setRotation(-23);
		isAlive = true;
		isMovingRight = true;
		isMovingLeft = false;
		isMovingUp = true;
		isMovingDown = false;
	}

	void move(sf::Vector2f distance) {
		head.move(distance);
		rEye.move(distance);
		lEye.move(distance);
		mouth.move(distance);
		neck.move(distance);
		body.move(distance);
		rHand.move(distance);
		lHand.move(distance);
		rArm.move(distance);
		rGauntlet.move(distance);
		rJewel.move(distance);
		lArm.move(distance);
		lGauntlet.move(distance);
		lJewel.move(distance);
	}

	void drawTo(sf::RenderWindow &window) {
		window.draw(head);
		window.draw(rEye);
		window.draw(lEye);
		window.draw(mouth);
		window.draw(neck);
		window.draw(body);
		window.draw(rHand);
		window.draw(lHand);
		window.draw(rArm);
		window.draw(rGauntlet);
		window.draw(rJewel);
		window.draw(lArm);
		window.draw(lGauntlet);
		window.draw(lJewel);
	}

	sf::Vector2f getPos() {
		return { head.getPosition().x, head.getPosition().y };
	}

	void setInitialHealth(int level) {
		life = 10 * level;
	}

	void hitHealth() {
		life-- ;
	}

	int getHealth() {
		return life;
	}

	sf::Vector2f getRightHand() {
		return { rHand.getPosition().x+30,rHand.getPosition().y };
	}

	sf::Vector2f getLeftHand() {
		return { lHand.getPosition().x - 30,lHand.getPosition().y };
	}

	void setIsAlive(boolean a) {
		isAlive = a;
	}

	boolean getIsAlive() {
		return isAlive;
	}
	void setIsMovingRight(boolean a) {
		isMovingRight = a;
	}

	boolean getIsMovingRight() {
		return isMovingRight;
	}

	void setIsMovingLeft(boolean a) {
		isMovingLeft = a;
	}

	boolean getIsMovingLeft() {
		return isMovingLeft;
	}

	void setIsMovingUp(boolean a) {
		isMovingUp = a;
	}

	boolean getIsMovingUp() {
		return isMovingUp;
	}

	void setIsMovingDown(boolean a) {
		isMovingDown = a;
	}

	boolean getIsMovingDown() {
		return isMovingDown;
	}

	boolean isCollidingWithBullet(Bullet * bullet) {
		if ((rArm.getGlobalBounds().intersects(bullet->getBullet().getGlobalBounds())) || (lArm.getGlobalBounds().intersects(bullet->getBullet().getGlobalBounds())) || (body.getGlobalBounds().intersects(bullet->getBullet().getGlobalBounds()))) {
			return true;
		}
		return false;
	}

	void destruct() {
		head.setPosition({ 2000,2000 });
		rEye.setPosition({ 2000,2000 });
		lEye.setPosition({ 2000,2000 });
		mouth.setPosition({ 2000,2000 });
		neck.setPosition({ 2000,2000 });
		body.setPosition({ 2000,2000 });
		rArm.setPosition({ 2000,2000 });
		lArm.setPosition({ 2000,2000 });
		rHand.setPosition({ 2000,2000 });
		rGauntlet.setPosition({ 2000,2000 });
		rJewel.setPosition({ 2000,2000 });
		lHand.setPosition({ 2000,2000 });
		lGauntlet.setPosition({ 2000,2000 });
		lJewel.setPosition({ 2000,2000 });
	}


private:
	EllipseShape head;
	sf::CircleShape rEye;
	sf::CircleShape lEye;
	EllipseShape mouth;
	sf::RectangleShape neck;
	sf::ConvexShape body;
	sf::RectangleShape rArm;
	sf::RectangleShape lArm;
	EllipseShape rHand;
	EllipseShape rGauntlet;
	EllipseShape rJewel;
	EllipseShape lHand;
	EllipseShape lGauntlet;
	EllipseShape lJewel;
	int life;
	boolean isAlive;
	boolean isMovingRight;
	boolean isMovingLeft;
	boolean isMovingUp;
	boolean isMovingDown;

};