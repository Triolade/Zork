#include "pch.h"
#include "ActionFactory.h"

Action* ActionFactory::createEmptyAction()
{
	return new EmptyAction();
}

Action* ActionFactory::createInvalidAction()
{
	return new InvalidAction();
}

Action* ActionFactory::createLookAction()
{
	return new LookAction();
}

Action* ActionFactory::createHelpAction()
{
	return new HelpAction();
}

Action* ActionFactory::createGoAction(common_defs::tokens direction)
{
	return new GoAction();
}

Action* ActionFactory::createOpenAction(common_defs::tokens item)
{
	return new OpenAction();
}

Action* ActionFactory::createDropAction(common_defs::tokens item)
{
	return new DropAction();
}

Action* ActionFactory::createTakeAction(common_defs::tokens item)
{
	return new TakeAction();
}

Action* ActionFactory::createCheckAction(common_defs::tokens item)
{
	return new CheckAction();
}

Action* ActionFactory::createAttackAction(common_defs::tokens enemy, common_defs::tokens weapon)
{
	return new AttackAction();
}

Action* ActionFactory::createOpenAction(common_defs::tokens item, common_defs::tokens opener)
{
	return new OpenAction();
}

Action* ActionFactory::createPutAction(common_defs::tokens item, common_defs::tokens container)
{
	return new PutAction();
}
