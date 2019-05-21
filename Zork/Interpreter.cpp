#include "pch.h"
#include "Utils.h"
#include "Interpreter.h"
#include "ActionFactory.h"

Interpreter::Interpreter(vector<common_defs::tokens> tokens)
{
	this->tokens = tokens;
}


Action* Interpreter::interpret() {
	Action* interpreted_action;

	const int num_tokens = tokens.size();
	switch (num_tokens) {
	case 0:
		interpreted_action = ActionFactory::createEmptyAction();
		break;

	case 1:
		interpreted_action = interpretOneTokenAction();
		break;

	case 2:
		interpreted_action = interpretTwoTokensAction();
		break;

	case 4:
		interpreted_action = interpretFourTokensAction();
		break;

	default:
		interpreted_action = ActionFactory::createInvalidAction();
	}

	return interpreted_action;
}

Action* Interpreter::interpretOneTokenAction() {
	Action* interpreted_action;

	if (tokens[0] == common_defs::LOOK) {
		interpreted_action = ActionFactory::createLookAction();
	}
	else if (tokens[0] == common_defs::HELP) {
		interpreted_action = ActionFactory::createHelpAction();
	}
	else if (tokens[0] == common_defs::INVENTORY) {
		interpreted_action = ActionFactory::createInventoryAction();
	}
	else {
		interpreted_action = ActionFactory::createInvalidAction();
	}

	return interpreted_action;
}

Action* Interpreter::interpretTwoTokensAction() {
	Action* interpreted_action;
	if (tokens[0] == common_defs::GO & Utils::isDirection(tokens[1])) {
		interpreted_action = ActionFactory::createGoAction(tokens[1]);
	}
	else if (tokens[0] == common_defs::OPEN & Utils::isItem(tokens[1])) {
		interpreted_action = ActionFactory::createOpenAction(tokens[1]);
	}
	else if (tokens[0] == common_defs::TAKE & Utils::isItem(tokens[1])) {
		interpreted_action = ActionFactory::createTakeAction(tokens[1]);
	}
	else if (tokens[0] == common_defs::DROP & Utils::isItem(tokens[1])) {
		interpreted_action = ActionFactory::createDropAction(tokens[1]);
	}
	else if (tokens[0] == common_defs::CHECK & Utils::isItem(tokens[1])) {
		interpreted_action = ActionFactory::createCheckAction(tokens[1]);
	}
	else if (tokens[0] == common_defs::ATTACK & Utils::isEnemy(tokens[1])) {
		interpreted_action = ActionFactory::createAttackAction(tokens[1]);
	}
	else {
		interpreted_action = ActionFactory::createInvalidAction();
	}

	return interpreted_action;
}

Action* Interpreter::interpretFourTokensAction() {
	Action* interpreted_action;
	if (
		tokens[0] == common_defs::OPEN
		& Utils::isItem(tokens[1])
		& tokens[2] == common_defs::WITH
		& Utils::isItem(tokens[3])
		) {
		interpreted_action = ActionFactory::createOpenAction(tokens[1], tokens[3]);
	}
	else if (
		tokens[0] == common_defs::PUT
		& Utils::isItem(tokens[1])
		& tokens[2] == common_defs::INTO
		& Utils::isItem(tokens[3])
		) {
		interpreted_action = ActionFactory::createPutAction(tokens[1], tokens[3]);
	}
	else {
		interpreted_action = ActionFactory::createInvalidAction();
	}

	return interpreted_action;
}



