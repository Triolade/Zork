#include "pch.h"
#include "HelpAction.h"


HelpAction::HelpAction()
{
	generatedOutput = "Full list of commands:"
		"\n"
		"The 'HELP' displays the text that you are reading right now.\n"
		"The 'SELF' command lists your stats, equipment and objects in your possession.\n"
		"The 'LOOK' command prints a description of your surroundings.\n"
		"The 'GO [NORTH|SOUTH|EAST|WEST]' command moves you to the chossen direction.\n"
		"The '[TAKE|PICK] [ITEM]' command makes you pick an item from the floor.\n"
		"The 'DROP [ITEM]' command makes you drop an item from the floor.\n"
		"The 'PUT [ITEM] INTO [CONTAINER]' command makes you put an item into a container.\n"
		"The 'CHECK [ITEM]' command shows you information of an item in your possesion.\n"
		"The 'ATTACK [ENEMY]' command makes you attack an enemy with your equipped weapon.\n"
		"The 'OPEN DOOR' command opens a door of the current room, if any. It consumes a key.\n"
		"\n"
		"Fighting:\n"
		"\n"
		"The result of a fight is decided by the attack of the player and the defense of the enemy.\nIf attack is greater than the defense the enemy will be killed.\nOtherwise, player will lose a live.\nRunning out of lives means GAME OVER.\n";		
}

void HelpAction::execute()
{

}

string HelpAction::getGeneratedOutput()
{
	return generatedOutput;
}