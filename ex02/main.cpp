#include "Array/Array.hpp"

/* ############################################################################################## */

#include "ColorFormatLib/ColorFormat.hpp"
#include "InputLib/Input.hpp"

/* ############################################################################################## */

#include <cctype>
#include <ctime>
#include <iomanip>
#include <iostream>

/* ############################################################################################## */

int main( void ) {
	try {
		std::cout << "\nWelcome to the templates program ”" << ColorFormat::formatString("ArrayPlate™", "magenta", "blink", "bold") << "“!" << std::endl;
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
			floating[index] = static_cast<float>(index + 1);
			if (index < 52)
				index < 26	? alphabet[index] = 'A' + index
							: alphabet[index] = 'a' + index - 26;
		}

		while (true) {
			std::ostringstream stream;

			std::cout << "_______________________________________________________________________________\n" << std::endl;
			std::cout << "You can test ”" << ColorFormat::formatString("INT", "blue", "italic")	 		 	 << "“ for integers, ”"
										  << ColorFormat::formatString("FLOAT", "green", "italic")		 	 << "“ for floatings, \n”"
										  << ColorFormat::formatString("CHAR", "magenta", "italic")			 << "“ for characters, ”"
										  << ColorFormat::formatString("STR", "yellow", "italic")		 	 << "“ for strings or ”"
										  << ColorFormat::formatString("EXIT", "red", "italic")				 << "“ to quit!" << std::endl;
			std::cout << "_______________________________________________________________________________\n" << std::endl;

			Input  userInput;
			std::cout << std::fixed << std::setprecision(1) << std::endl;

			if (userInput.stringFormat() == "INT") {
				Array<int> integerArray(100);
				fillArray(integerArray, integer, 100);

				const int randomIndex = std::rand() % 100; stream << randomIndex + 1;
				std::cout << "Let's take the index " << ColorFormat::formatString(stream.str(), "cyan") << " of the array of integers: " << integerArray[randomIndex] << std::endl;
			}
			else if (userInput.stringFormat() == "FLOAT") {
				Array<float> floatingArray(100);
				fillArray(floatingArray, floating, 100);

				const int randomIndex = std::rand() % 100; stream << randomIndex + 1;
				std::cout << "Let's take the index " << ColorFormat::formatString(stream.str(), "cyan") << " of the array of floatings: " << floatingArray[randomIndex] << 'f' << std::endl;
			}
			else if (userInput.stringFormat() == "CHAR") {
				Array<char> characterArray(52);
				fillArray(characterArray, alphabet, 52);

				const int randomIndex = std::rand() % 52; stream << randomIndex + 1;
				std::cout << "Let's take the index " << ColorFormat::formatString(stream.str(), "cyan") << " of the array of characters: " << characterArray[randomIndex] << std::endl;
			}
			else if (userInput.stringFormat() == "STR") {
				Array<std::string> stringArray(42);
				fillArray(stringArray, words, 42);

				const int randomIndex = std::rand() % 42; stream << randomIndex + 1;
				std::cout << "Let's take the index " << ColorFormat::formatString(stream.str(), "cyan") << " of the array of strings: " << stringArray[randomIndex] << std::endl;
			}
			else if (userInput.stringFormat() == "EXIT")
				break;
			else
				std::cout << ColorFormat::formatString("Unclear instructions!", "red", "bold") << std::endl;
		}
		std::cout << "\nThanks for using ”" << ColorFormat::formatString("ArrayPlate™", "magenta", "blink", "bold")					  << "“!\n"	  << std::endl;
	} catch (std::exception &e) { std::cerr << ColorFormat::formatString("The following error has been encountered: ", "red", "bold") << e.what() << std::endl; }
	return 0;
}