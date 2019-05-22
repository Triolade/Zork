#include "pch.h"
#include "SphinxAction.h"
#include "WeaponFactory.h"
#include <stdio.h>
#include "OutputManager.h"
#include "GameManager.h"
#include "Player.h"

SphinxAction::SphinxAction() {
	

}

void SphinxAction::execute() {
	string sphinxSpech = "Greetings adventurer. I'm the great sphinx of Gizeh and I'm here to test your mind.\nIf you prove your knowledge I will give you unlimited power.\nOtherwise, I will devour you.\n\nHere is my question:\n";
	string sphinxQuestion = "'Which creature has one voice and yet becomes four - footed and two - footed and three - footed ?'";

	string output = "The sphinxs talks to you:\n\n" + sphinxSpech + sphinxQuestion + "\nIntroduce your answer:";
	OutputManager::instance().printOutput(output);

	string answer;
	cin >> answer;

	if (answer != "MAN") {
		OutputManager::instance().printOutput("Incorrect! Prepared to be devoured.");
		GameManager::instance().triggerGameEnding(GameManager::end_game_reason::DEATH);
	}
	else {
		OutputManager::instance().printOutput("Correct! It's dangerous to go alone, take this.");
		Weapon naratia = WeaponFactory::createSword();
		Player::instance().pickWeapon(naratia);
		OutputManager::instance().printOutput("You obtained a legendary sword.");
	}
}

string SphinxAction::getGeneratedOutput() {
	return "";
}
