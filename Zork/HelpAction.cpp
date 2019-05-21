#include "pch.h"
#include "HelpAction.h"


HelpAction::HelpAction()
{
	generatedOutput = "Full list of commands:"
		"\n"
		"The 'INFO' command prints information which might give some idea of what the game is about.\n"
		"The 'QUIT' command asks whether you wish to continue playing.\n"
		"The 'INVENTORY' command lists the objects in your possession.\n"
		"The 'LOOK' command prints a description of your surroundings.\n"
		"The 'TIME' command tells you how long you have been playing.\n"
		"\n"
		"Fighting:\n"
		"\n"
		"Zombies will, as a rule, try to eat you. In order to defend yourself you migh try the command 'ATTACK <zombie> WITH <weapon>', that may or may not be useful. Some weapons might require ammunation or fuel in order to work.\n";		
}

void HelpAction::execute()
{

}

string HelpAction::getGeneratedOutput()
{
	return generatedOutput;
}