#include "iter.hpp"

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"
#include "InputLib/Input.hpp"

/* ############################################################################################## */

#include <cctype>
#include <iostream>

/* ############################################################################################## */

static void addFourtyFour(std::string &string) { string += "_42";																   }
static void changeSize(char &character)		   { character = character >= 'a' ? std::toupper(character) : std::tolower(character); }
static void incrementInteger(int &integer)	   { ++integer;																		   }
static void scaleFloating(float &floating)	   { floating *= 1.5;																   }

int main( void ) {
	try {
		std::cout << "\nWelcome to the templates program ”" << ColorFormat::formatString("Iter™", "blue", "blink", "bold") << "“!" << std::endl;

		int			integer[100];
		float		floating[100];
		char		alphabet[52];
		std::string	words[42] = {
			"Zéphyr",	   "Abracadabra", "Bamboche",	   "Chachou",	   "Dodelinerie",
			"Enigmatique", "Farfelu",	  "Gargantuesque", "Histrion",	   "Irrévérencieux",
			"Jovial",	   "Kaboom",	  "Ludique",	   "Méliflu",	   "Nostalgique",
			"Olibrius",	   "Pétille",	  "Quirky",		   "Rabelaisien",  "Sardonique",
			"Tartuffe",	   "Utile",		  "Vagabond",	   "Wagon",		   "Xénophile",
			"Yodler",	   "Zygomatique", "Ambidextre",	   "Boustifaille", "Cocasse",
			"Dynamo",	   "Eblouissant", "Fulgurant",	   "Gourmand",	   "Hypnotique",
			"Illustre",	   "Jubilatoire", "Kamikaze",	   "Ludique",	   "Magique",
			"Nébuleux",	   "Opulent"
		};

		for (size_t index	= 0 ; index < 100 ; index++) {
			integer[index]	= index + 1;
			floating[index] = static_cast<float>(index + 1);
			if (index < 52)
				index < 26	? alphabet[index] = 'A' + index
							: alphabet[index] = 'a' + index - 26;
		}

		while (true) {
			std::cout << "_______________________________________________________________________________\n" << std::endl;
			std::cout << "You can test ”" << ColorFormat::formatString("INT", "blue", "italic")	 		 	 << "“ for integers, ”"
										  << ColorFormat::formatString("FLOAT", "green", "italic")		 	 << "“ for floatings, \n”"
										  << ColorFormat::formatString("CHAR", "magenta", "italic")			 << "“ for characters, ”"
										  << ColorFormat::formatString("STR", "yellow", "italic")		 	 << "“ for strings or ”"
										  << ColorFormat::formatString("EXIT", "red", "italic")				 << "“ to quit!" << std::endl;
			std::cout << "_______________________________________________________________________________\n" << std::endl;

			Input  userInput; std::cout << std::endl;

			if (userInput.stringFormat() == "INT") {
				std::cout << "Initial list: " << arrayToString(integer, 100) << std::endl;
				iter(integer, 100, &incrementInteger);
				std::cout << "\nList after " << ColorFormat::formatString("incrementation", "blue") << " iteration: " << arrayToString(integer, 100) << std::endl;
			}
			else if (userInput.stringFormat() == "FLOAT") {
				std::cout << "Initial list: " << arrayToString(floating, 100) << std::endl;
				iter(floating, 100, &scaleFloating);
				std::cout << "\nList after " << ColorFormat::formatString("scaling", "green") << " iteration: " << arrayToString(floating, 100) << std::endl;
			}
			else if (userInput.stringFormat() == "CHAR") {
				std::cout << "Initial list: " << arrayToString(alphabet, 52) << std::endl;
				iter(alphabet, 52, &changeSize);
				std::cout << "\nList after " << ColorFormat::formatString("changing case", "magenta") << " iteration: " << arrayToString(alphabet, 52) << std::endl;
			}
			else if (userInput.stringFormat() == "STR") {
				std::cout << "Initial list: " << arrayToString(words, 42) << std::endl;
				iter(words, 42, &addFourtyFour);
				std::cout << "\nList after iteration of " << ColorFormat::formatString("adding a suffix", "yellow") << ": " << arrayToString(words, 42) << std::endl;
			}
			else if (userInput.stringFormat() == "EXIT")
				break;
			else
				std::cout << ColorFormat::formatString("Unclear instructions!", "red", "bold") << std::endl;
		}
		std::cout << "\nThanks for using ”" << ColorFormat::formatString("Iter™", "blue", "blink", "bold")							  << "“!\n"	  << std::endl;
	} catch (std::exception &e) { std::cerr << ColorFormat::formatString("The following error has been encountered: ", "red", "bold") << e.what() << std::endl; }
	return 0;
}
