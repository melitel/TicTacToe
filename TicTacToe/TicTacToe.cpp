#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main()
{
    if (1) {
		Game game;
		game.run();
    }
    else {
		sf::RenderWindow window(sf::VideoMode(sf::Vector2u(265, 350)), "My window");
		// run the program as long as the window is open
		while (window.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// clear the window with black color
			window.clear(sf::Color::Black);

			// draw everything here...
			sf::RectangleShape rectangle(sf::Vector2f(265.f, 350.f));

			{
				rectangle.setFillColor(sf::Color(0, 0, 0));
			}

			sf::RectangleShape rectangle1(sf::Vector2f(75.f, 75.f));

			{
				rectangle1.setFillColor(sf::Color(255, 255, 255));
				rectangle1.setPosition(sf::Vector2f(10.f, 40.f));
			}

			sf::RectangleShape rectangle2(sf::Vector2f(75.f, 75.f));

			{
				rectangle2.setFillColor(sf::Color(255, 255, 255));
				rectangle2.setPosition(sf::Vector2f(95.f, 40.f));
			}

			sf::RectangleShape rectangle3(sf::Vector2f(75.f, 75.f));

			{
				rectangle3.setFillColor(sf::Color(255, 255, 255));
				rectangle3.setPosition(sf::Vector2f(180.f, 40.f));
			}

			sf::RectangleShape rectangle4(sf::Vector2f(75.f, 75.f));

			{
				rectangle4.setFillColor(sf::Color(255, 255, 255));
				rectangle4.setPosition(sf::Vector2f(10.f, 125.f));
			}

			sf::RectangleShape rectangle5(sf::Vector2f(75.f, 75.f));

			{
				rectangle5.setFillColor(sf::Color(255, 255, 255));
				rectangle5.setPosition(sf::Vector2f(95.f, 125.f));
			}

			sf::RectangleShape rectangle6(sf::Vector2f(75.f, 75.f));

			{
				rectangle6.setFillColor(sf::Color(255, 255, 255));
				rectangle6.setPosition(sf::Vector2f(180.f, 125.f));
			}

			sf::RectangleShape rectangle7(sf::Vector2f(75.f, 75.f));

			{
				rectangle7.setFillColor(sf::Color(255, 255, 255));
				rectangle7.setPosition(sf::Vector2f(10.f, 210.f));
			}

			sf::RectangleShape rectangle8(sf::Vector2f(75.f, 75.f));

			{
				rectangle8.setFillColor(sf::Color(255, 255, 255));
				rectangle8.setPosition(sf::Vector2f(95.f, 210.f));
			}

			sf::RectangleShape rectangle9(sf::Vector2f(75.f, 75.f));

			{
				rectangle9.setFillColor(sf::Color(255, 255, 255));
				rectangle9.setPosition(sf::Vector2f(180.f, 210.f));
			}

			sf::RectangleShape rectangle10(sf::Vector2f(245.f, 45.f));

			{
				rectangle10.setFillColor(sf::Color(255, 255, 255));
				rectangle10.setPosition(sf::Vector2f(10.f, 295.f));
			}
			
			// text
			sf::Text text;
			sf::Font font;
			// select the font
			{
				
				if (!font.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font.setSmooth(false);
				text.setFont(font); // font is a sf::Font

				// set the string to display
				text.setString("Make your move");

				// set the character size
				text.setCharacterSize(14); // in pixels, not points!

				// set the color
				text.setFillColor(sf::Color::White);

				// set the text style
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);
				text.setPosition(sf::Vector2f(10.f, 10.f));
			}

			sf::Text number1;
			sf::Font font1;
			// select the font
			{

				if (!font1.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font1.setSmooth(false);
				number1.setFont(font); // font is a sf::Font

				// set the string to display
				number1.setString("1");

				// set the character size
				number1.setCharacterSize(45); // in pixels, not points!

				// set the color
				number1.setFillColor(sf::Color::Black);

				// set the text style
				number1.setStyle(sf::Text::Bold);
				number1.setPosition(sf::Vector2f(30.f, 50.f));
			}

			sf::Text number2;
			sf::Font font2;
			// select the font
			{

				if (!font2.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font2.setSmooth(false);
				number2.setFont(font); // font is a sf::Font

				// set the string to display
				number2.setString("2");

				// set the character size
				number2.setCharacterSize(45); // in pixels, not points!

				// set the color
				number2.setFillColor(sf::Color::Black);

				// set the text style
				number2.setStyle(sf::Text::Bold);
				number2.setPosition(sf::Vector2f(120.f, 50.f));
			}

			sf::Text number3;
			sf::Font font3;
			// select the font
			{						
				if (!font3.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font3.setSmooth(false);
				number3.setFont(font); // font is a sf::Font

				// set the string to display
				number3.setString("3");

				// set the character size
				number3.setCharacterSize(45); // in pixels, not points!

				// set the color
				number3.setFillColor(sf::Color::Black);

				// set the text style
				number3.setStyle(sf::Text::Bold);
				number3.setPosition(sf::Vector2f(200.f, 50.f));
			}

			sf::Text number4;
			sf::Font font4;
			// select the font
			{

				if (!font4.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font4.setSmooth(false);
				number4.setFont(font); // font is a sf::Font

				// set the string to display
				number4.setString("4");

				// set the character size
				number4.setCharacterSize(45); // in pixels, not points!

				// set the color
				number4.setFillColor(sf::Color::Black);

				// set the text style
				number4.setStyle(sf::Text::Bold);
				number4.setPosition(sf::Vector2f(30.f, 135.f));
			}

			sf::Text number5;
			sf::Font font5;
			// select the font
			{

				if (!font5.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font5.setSmooth(false);
				number5.setFont(font); // font is a sf::Font

				// set the string to display
				number5.setString("5");

				// set the character size
				number5.setCharacterSize(45); // in pixels, not points!

				// set the color
				number5.setFillColor(sf::Color::Black);

				// set the text style
				number5.setStyle(sf::Text::Bold);
				number5.setPosition(sf::Vector2f(120.f, 135.f));
			}

			sf::Text number6;
			sf::Font font6;
			// select the font
			{

				if (!font6.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font6.setSmooth(false);
				number6.setFont(font); // font is a sf::Font

				// set the string to display
				number6.setString("6");

				// set the character size
				number6.setCharacterSize(45); // in pixels, not points!

				// set the color
				number6.setFillColor(sf::Color::Black);

				// set the text style
				number6.setStyle(sf::Text::Bold);
				number6.setPosition(sf::Vector2f(200.f, 135.f));
			}

			sf::Text number7;
			sf::Font font7;
			// select the font
			{

				if (!font7.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font7.setSmooth(false);
				number7.setFont(font); // font is a sf::Font

				// set the string to display
				number7.setString("7");

				// set the character size
				number7.setCharacterSize(45); // in pixels, not points!

				// set the color
				number7.setFillColor(sf::Color::Black);

				// set the text style
				number7.setStyle(sf::Text::Bold);
				number7.setPosition(sf::Vector2f(30.f, 220.f));
			}

			sf::Text number8;
			sf::Font font8;
			// select the font
			{

				if (!font8.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font8.setSmooth(false);
				number8.setFont(font); // font is a sf::Font

				// set the string to display
				number8.setString("8");

				// set the character size
				number8.setCharacterSize(45); // in pixels, not points!

				// set the color
				number8.setFillColor(sf::Color::Black);

				// set the text style
				number8.setStyle(sf::Text::Bold);
				number8.setPosition(sf::Vector2f(120.f, 220.f));
			}

			sf::Text number9;
			sf::Font font9;
			// select the font
			{

				if (!font9.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font9.setSmooth(false);
				number9.setFont(font); // font is a sf::Font

				// set the string to display
				number9.setString("9");

				// set the character size
				number9.setCharacterSize(45); // in pixels, not points!

				// set the color
				number9.setFillColor(sf::Color::Black);

				// set the text style
				number9.setStyle(sf::Text::Bold);
				number9.setPosition(sf::Vector2f(200.f, 220.f));
			}

			sf::Text results;
			sf::Font font_res;
			// select the font
			{

				if (!font_res.loadFromFile("arial.ttf"))
				{
					int ii = 10;
				}
				font_res.setSmooth(false);
				results.setFont(font); // font is a sf::Font

				// set the string to display
				results.setString("X	" "Won");

				// set the character size
				results.setCharacterSize(25); // in pixels, not points!

				// set the color
				results.setFillColor(sf::Color::Black);

				// set the text style
				results.setStyle(sf::Text::Bold);
				results.setPosition(sf::Vector2f(50.f, 305.f));
			}

			window.draw(rectangle);
			window.draw(text);
			window.draw(rectangle1);
			window.draw(rectangle2);
			window.draw(rectangle3);
			window.draw(rectangle4);
			window.draw(rectangle5);
			window.draw(rectangle6);
			window.draw(rectangle7);
			window.draw(rectangle8);
			window.draw(rectangle9);
			window.draw(rectangle10);
			window.draw(number1);
			window.draw(number2);
			window.draw(number3);
			window.draw(number4);
			window.draw(number5);
			window.draw(number6);
			window.draw(number7);
			window.draw(number8);
			window.draw(number9);
			window.draw(results);

			// end the current frame
			window.display();
		}

		return 0;
    }

}

