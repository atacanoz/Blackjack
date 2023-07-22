#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <cstdlib>


int main() {
	sf::RenderWindow window(sf::VideoMode(1100, 800), "Program", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(144);
	window.setMouseCursorVisible(true);

	sf::SoundBuffer buffershuffle;
	buffershuffle.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\shuffling.wav");
	
	sf::Sound shuffle;
	shuffle.setBuffer(buffershuffle);
	shuffle.setVolume(50);

	sf::Font font;
	font.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\Diana Zetta.ttf");

	sf::Texture decktexture;
	decktexture.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\deck.png");

	sf::Texture hitbuttontexture;
	hitbuttontexture.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\hitbutton.png");

	sf::Texture hitbuttontexture2;
	hitbuttontexture2.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\hitbutton2.png");

	sf::Texture standbuttontexture;
	standbuttontexture.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\standbutton.png");

	sf::Texture standbuttontexture2;
	standbuttontexture2.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\standbutton2.png");

	sf::Texture dealbuttontexture;
	dealbuttontexture.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\dealbutton.png");

	sf::Texture dealbuttontexture2;
	dealbuttontexture2.loadFromFile("C:\\Users\\ccll7\\Desktop\\SFML Files\\dealbutton2.png");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(0.5);


	sf::RectangleShape cardback(sf::Vector2f(150, 225));
	cardback.setTexture(&decktexture);

	sf::RectangleShape card(sf::Vector2f(150, 225));
	card.setTexture(&decktexture);
	card.setPosition(-500, -500);

	sf::Vector2u decksize;
	decksize = decktexture.getSize();

	sf::RectangleShape standbutton(sf::Vector2f(150, 70));
	standbutton.setTexture(&standbuttontexture);
	standbutton.setPosition(750, 600);

	sf::RectangleShape standbutton2(sf::Vector2f(150, 70));
	standbutton2.setTexture(&standbuttontexture2);
	standbutton2.setPosition(750, 600);

	sf::RectangleShape hitbutton(sf::Vector2f(150, 70));
	hitbutton.setTexture(&hitbuttontexture);
	hitbutton.setPosition(250, 600);

	sf::RectangleShape hitbutton2(sf::Vector2f(150, 70));
	hitbutton2.setTexture(&hitbuttontexture2);
	hitbutton2.setPosition(250, 600);

	sf::RectangleShape dealbutton(sf::Vector2f(200, 100));
	dealbutton.setTexture(&dealbuttontexture);
	dealbutton.setPosition(465, 200);

	sf::RectangleShape dealbutton2(sf::Vector2f(200, 100));
	dealbutton2.setTexture(&dealbuttontexture2);
	dealbutton2.setPosition(465, 200);

	decksize.x /= 14;
	decksize.y /= 4;

	there:

	srand(time(0) * 1000);
	
	std::vector<sf::RectangleShape> cards;

	int fourcards[4]{};

	int x = 550;
	int a = 530;
	int b = 470;
	int card4x = 0;
	int card4y = 0;
	int drawx = 0;
	int drawy = 0;
	int cardvalue = 0;
	int card_draw = 0;
	bool animationdone = false;
	bool animationstanddone = false;
	bool firstcalculation = false;
	int animationdone1 = 0;
	bool dealt = false;
	int hand = 0;
	int croupier = 0;
	bool standornot = false;
	bool win = false;
	bool push = false;
	bool game_over = false;
	bool blackjack = false;
	bool conditionsdone = false;

	sf::Clock c1;
	sf::Clock c2;
	sf::Clock c3;
	sf::Clock c4;
	sf::Clock c5;
	sf::Clock c6;
	sf::Clock c7;

	while (window.isOpen()) {
		sf::Vector2i mousepos = sf::Mouse::getPosition(window);
		//std::cout << mousepos.x << " " << mousepos.y << std::endl;
		sf::Event ev;
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			case sf::Event::MouseButtonPressed:
				if (ev.key.code == sf::Mouse::Left) {
					if ((mousepos.x >= 250 && mousepos.x <= 400) && (mousepos.y >= 600 && mousepos.y <= 670) && (animationdone == true && standornot == false) && game_over == false) {
						drawx = rand() % 13;
						drawy = rand() % 4;
						cards.push_back(sf::RectangleShape(card));
						cards[card_draw].setTextureRect(sf::IntRect(decksize.x * 13, decksize.y * 1, decksize.x, decksize.y));
						cards.back().setPosition(900, 100);
						if (drawx == 0) {
							cardvalue = 1;
						}
						if (0 < drawx && drawx < 9) {
							cardvalue = drawx + 1;
						}
						if (drawx > 8) {
							cardvalue = 10;
						}
						hand += cardvalue;
						card_draw++;
						std::cout << "card: " << card_draw << std::endl;
						std::cout << cardvalue << std::endl;
						animationdone = false;
					}
				}
				if (ev.key.code == sf::Mouse::Left) {
					if ((mousepos.x >= 460 && mousepos.x <= 660) && (mousepos.y >= 200 && mousepos.y <= 300)) {
						if (dealt == false) {
							for (int i = 0; i < 4; i++) {
								drawx = rand() % 13;
								drawy = rand() % 4;
								cards.push_back(sf::RectangleShape(card));
								if (i < 3) {
									cards[i].setTextureRect(sf::IntRect(decksize.x * drawx, decksize.y * drawy, decksize.x, decksize.y));
								}
								else {
									cards[i].setTextureRect(sf::IntRect(decksize.x * 13, decksize.y * 1, decksize.x, decksize.y));
									card4x = drawx;
									card4y = drawy;
								}
								if (drawx == 0) {
									cardvalue = 1;
								}
								if (0 < drawx && drawx < 9) {
									cardvalue = drawx + 1;
								}
								if (drawx > 8) {
									cardvalue = 10;
								}
								fourcards[i] = cardvalue;
								cards.back().setPosition(900, 100);
								card_draw++;
								std::cout << "card: " << card_draw << std::endl;
								std::cout << cardvalue << std::endl;
							}
							dealt = true;
						}
					}
				}
				if (ev.key.code == sf::Mouse::Left) {
					if ((mousepos.x >= 750 && mousepos.x <= 900) && (mousepos.y >= 600 && mousepos.y <= 670) && (animationdone1 == 4 && standornot == false)) {
						cards[3].setTextureRect(sf::IntRect(decksize.x * card4x, decksize.y * card4y, decksize.x, decksize.y));
						animationstanddone = true;
						standornot = true;
					}
				}
			}
		}

		cardback.setTextureRect(sf::IntRect(decksize.x * 13, decksize.y * 1, decksize.x, decksize.y));
		cardback.setPosition(900, 100);

		//game logic

		if ((dealt == true) && (firstcalculation == false)) {
			if (fourcards[1] == 1 || fourcards[3] == 1) {
				croupier = fourcards[1] + fourcards[3] + 10;
				if (croupier == 21) {
					cards[3].setTextureRect(sf::IntRect(decksize.x * card4x, decksize.y * card4y, decksize.x, decksize.y));
					std::cout << "croupier wins!" << std::endl;
					game_over = true;
				}
				else {
					std::cout << croupier - 10 << "/" << croupier << std::endl;
					croupier -= 10;
				}
			}
			if (fourcards[0] == 1 || fourcards[2] == 1) {
				hand = fourcards[0] + fourcards[2] + 10;
				if (hand == 21) {
					cards[3].setTextureRect(sf::IntRect(decksize.x * card4x, decksize.y * card4y, decksize.x, decksize.y));
					std::cout << "blackjack" << std::endl;
					game_over = true;
					if (hand == croupier) {
						win = false;
					}
					win = true;
					blackjack = true;
				}
				else {
					std::cout << hand - 10 << "/" << hand << std::endl;
					hand -= 10;
				}
			}
			if (fourcards[1] != 1 && fourcards[3] != 1) {
				croupier = fourcards[1] + fourcards[3];
			}
			if (fourcards[0] != 1 && fourcards[2] != 1) {
				hand = fourcards[0] + fourcards[2];
			}
			firstcalculation = true;
		}

		if ((fourcards[1] == 1 || fourcards[3] == 1) && (standornot == true)) {
			if (croupier <= 11 && croupier > 6) {
				croupier += 10;
			}
		}

		if ((fourcards[0] == 1 || fourcards[2] == 1) && (standornot == true)) {
			if (hand <= 11 && hand > 6) {
				hand += 10;
			}
		}

		if ((croupier < 17 && standornot == true) && animationstanddone == true) {
			drawx = rand() % 13;
			drawy = rand() % 4;
			cards.push_back(sf::RectangleShape(card));
			cards[card_draw].setTextureRect(sf::IntRect(decksize.x * drawx, decksize.y * drawy, decksize.x, decksize.y));
			cards.back().setPosition(900, 100);
			if (drawx == 0) {
				cardvalue = 1;
			}
			if (0 < drawx && drawx < 9) {
				cardvalue = drawx + 1;
			}
			if (drawx > 8) {
				cardvalue = 10;
			}
			animationstanddone = false;
			card_draw++;
			croupier = croupier + cardvalue;
		}

		if (hand > 21) {
			cards[3].setTextureRect(sf::IntRect(decksize.x * card4x, decksize.y * card4y, decksize.x, decksize.y));
			std::cout << "you bust!" << std::endl;
			game_over = true;
		}

		if (croupier > 21 && animationstanddone == true) {
			std::cout << "croupier busts!" << std::endl;
			win = true;
			game_over = true;
		}

		if ((croupier > 16 && croupier <= 21) && (standornot == true && animationstanddone == true)) {
			if (hand > croupier) {
				std::cout << "you win!" << std::endl;
				win = true;
				game_over = true;
			}
			if (hand == croupier) {
				std::cout << "push!" << std::endl;
				push = true;
				game_over = true;
			}
			if (hand < croupier) {
				std::cout << "you lost!" << std::endl;
				game_over = true;
			}
		}


		//Animations
		if (dealt == true) {
			if (c3.getElapsedTime().asMilliseconds() > 1 && animationdone1 == 0) {
				cards[0].move(-5, 5);
				if (cards[0].getPosition().x == 450) {
					animationdone1++;
				}
				c3.restart();
			}
		}

		if (animationdone1 == 1) {
			if (dealt == true) {
				if ((c3.getElapsedTime().asMilliseconds() > 1) && (card_draw < 5)) {
					cards[1].move(-5, 0);
					if (cards[1].getPosition().x == 450) {
						animationdone1++;
					}
					c3.restart();
				}
			}
		}

		if (animationdone1 == 2) {
			if (dealt == true) {
				if ((c3.getElapsedTime().asMilliseconds() > 1) && (card_draw < 5)) {
					cards[2].move(-5, 5);
					if (cards[2].getPosition().x == 490) {
						animationdone1++;
					}
					c3.restart();
				}
			}
		}

		if (animationdone1 == 3) {
			if (dealt == true) {
				if ((c3.getElapsedTime().asMilliseconds() > 1) && (card_draw < 5)) {
					cards[3].move(-5, 0);
					if (cards[3].getPosition().x == 500) {
						animationdone1++;
						animationdone = true;
					}
					c3.restart();
				}
			}
		}

		std::cout << card_draw << std::endl;
		std::cout << "player: " << hand << std::endl;
		std::cout << "croupier: " << croupier << std::endl;

		if ((c1.getElapsedTime().asMilliseconds() > 5 && card_draw > 4) && animationdone == false) {
			cards[card_draw - 1].move(-5, 5);
			if (cards[card_draw - 1].getPosition().x == a && cards[card_draw - 1].getPosition().y == b) {
				cards.back().setTextureRect(sf::IntRect(decksize.x * drawx, decksize.y * drawy, decksize.x, decksize.y));
				a += 40;
				b -= 40;
				animationdone = true;
			}
			c1.restart();
		}
		if (c6.getElapsedTime().asMilliseconds() > 1000) {
			if ((animationstanddone == false && standornot == true)) {
				if (c5.getElapsedTime().asMilliseconds() > 5) {
					cards[card_draw - 1].move(-5, 0);
					if (cards[card_draw - 1].getPosition().x == x) {
						x += 50;
						c6.restart();
						animationstanddone = true;
					}
					c5.restart();
				}
			}
		}
	
		if (game_over == true && conditionsdone == false) {
			if (blackjack == true) {
				text.setString("Blackjack!");
				text.setPosition(100, 350);
				text.setFillColor(sf::Color(255, 190, 0));
			}
			else if (win == true) {
				text.setString("You Win!");
				text.setPosition(100, 350);
				text.setFillColor(sf::Color(255, 190, 0));
			}
			else if (push == true) {
				text.setString("Push!");
				text.setPosition(100, 350);
				text.setFillColor(sf::Color(255, 190, 0));
			}
			else if (win == false) {
				text.setString("You Lost!");
				text.setPosition(100, 350);
				text.setFillColor(sf::Color(255, 0, 0));
			}
			c7.restart();
			conditionsdone = true;
		}

		std::cout << "cards " << cards.size() << std::endl;
			
		if (c7.getElapsedTime().asSeconds() > 5 && conditionsdone == true) {
			for (int i = 0; i < cards.size(); i++) {
				cards.erase(cards.begin() + i);
			}
			goto there;
		}

		window.clear(sf::Color(16, 106, 22));
		for (int i = 0; i < cards.size(); i++) {
			window.draw(cards[i]);
		}
		window.draw(cardback);
		if (dealt == false && game_over == false) {
			window.draw(dealbutton);
			if ((mousepos.x >= 460 && mousepos.x <= 660) && (mousepos.y >= 200 && mousepos.y <= 300)) {
				window.draw(dealbutton2);
			}
		}
		if (dealt == true && game_over == false) {
			if (animationdone == true && standornot == false) {
				window.draw(hitbutton);
				if ((mousepos.x >= 250 && mousepos.x <= 400) && (mousepos.y >= 600 && mousepos.y <= 670)) {
					window.draw(hitbutton2);
				}
			}
		}
		if (dealt == true && game_over == false) {
			if (animationdone == true && standornot == false) {
				window.draw(standbutton);
				if ((mousepos.x >= 750 && mousepos.x <= 900) && (mousepos.y >= 600 && mousepos.y <= 670)) {
					window.draw(standbutton2);
				}
			}
		}
		if (game_over == true) {
			window.draw(text);
		}
		window.display();
	}

	return 0;
}