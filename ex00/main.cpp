#include "Templates.hpp"

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"
#include "InputLib/Input.hpp"

/* ############################################################################################## */

#include <ctime>
#include <iostream>

/* ############################################################################################## */

int main( void ) {
	try {
		std::cout << "\nWelcome to the templates program ”" << ColorFormat::formatString("BasicPlate™", "green", "blink", "bold") << "“!" << std::endl;
		std::srand(static_cast<unsigned int>(std::time(NULL)));

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
			floating[index] = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 100.0f;
			if (index < 52)
				index < 26	? alphabet[index] = 'A' + index
							: alphabet[index] = 'a' + index - 26;
		}

		while (true) {
			std::cout << "_______________________________________________________________________________\n" << std::endl;
			std::cout << "You can test ”" << ColorFormat::formatString("INT", "blue", "italic")	 		 	 << "“ for integers, ”"
										   << ColorFormat::formatString("FLOAT", "green", "italic")		 	 << "“ for floatings, \n”"
										   << ColorFormat::formatString("CHAR", "magenta", "italic")		 << "“ for characters, ”"
										   << ColorFormat::formatString("STR", "yellow", "italic")		 	 << "“ for strings or ”"
										   << ColorFormat::formatString("EXIT", "red", "italic")			 << "“ to quit!" << std::endl;
			std::cout << "_______________________________________________________________________________\n" << std::endl;

			Input  userInput; std::cout << std::endl;
			size_t randomIndexA = std::rand() % 100;
			size_t randomIndexB = std::rand() % 100;

			if		(userInput.stringFormat() == "INT")		checkFunctions(integer[randomIndexA],		integer[randomIndexB]);
			else if (userInput.stringFormat() == "FLOAT")	checkFunctions(floating[randomIndexA],		floating[randomIndexB]);
			else if (userInput.stringFormat() == "CHAR")	checkFunctions(alphabet[randomIndexA % 52], alphabet[randomIndexB % 52]);
			else if (userInput.stringFormat() == "STR")		checkFunctions(words[randomIndexA % 42],	words[randomIndexB % 42]);
			else if (userInput.stringFormat() == "EXIT")	break;
			else											std::cout << ColorFormat::formatString("Unclear instructions!", "red", "bold") << std::endl;
		}
		std::cout << "\nThanks for using ”" << ColorFormat::formatString("BasicPlate™", "green", "blink", "bold")					  << "“!\n"	  << std::endl;
	} catch (std::exception &e) { std::cerr << ColorFormat::formatString("The following error has been encountered: ", "red", "bold") << e.what() << std::endl; }
	return 0;
}