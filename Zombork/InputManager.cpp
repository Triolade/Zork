#include "pch.h"
#include "Utils.h"
#include "InputManager.h"
#include "Interpreter.h"
#include "ActionFactory.h"

Action* InputManager::getActionFromInput() {
	// Gets input
	string input;
	getline(cin, input);

	// Splits input into tokens
	vector<common_defs::tokens> tokens;
	try {
		 tokens = tokenize(input);
	}
	catch (InvalidInputException* e) {
		delete e;
		return ActionFactory::createInvalidAction();
	}

	// Interprets tokens and generates requested
	Interpreter interpreter(tokens);
	Action* requestedAction = interpreter.interpret();
	return requestedAction;
}

vector<common_defs::tokens> InputManager::tokenize(string input) {
	vector<string> unprocessed_tokens = Utils::split(input, ' ');
	const int num_unprocessed_tokens = unprocessed_tokens.size();
	vector<common_defs::tokens> tokens = vector<common_defs::tokens>();
	int i = 0;
	bool invalidToken = false;
	while (!invalidToken & i < num_unprocessed_tokens) {
		if (isValidToken(unprocessed_tokens[i])) {
			tokens.push_back(tokens_mapping[unprocessed_tokens[i]]);
		}
		else {
			invalidToken = true;
		}
		++i;
	}

	if (invalidToken) {
		throw new InvalidInputException();
	}

	return tokens;
}

bool InputManager::isValidToken(string token) {
	return tokens_mapping.find(token) != tokens_mapping.end();
}