#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

using namespace std;

class Score
{
public:
	Score(string file) {
		

		if (!font.loadFromFile(file))
			cout<< "Error loading font"<< endl;

		else {
			score.setFont(font);
			score.setCharacterSize(35);
			score.setPosition({ 10,10 });
			score.setFillColor(sf::Color::White);
			score.setString("0");

		}
		
		
	}

	int getScore() {
		stringstream temp(score.getString());
		int res = 0;
		temp >> res;
		return res;
	}

	void setScore(int newScore) {
		stringstream temp;
		temp << newScore;
		score.setString(temp.str());
	}

	void display(sf::RenderWindow &window) {
		window.draw(score);
	}

private:
	sf::Text score;
	sf::Font font;
};