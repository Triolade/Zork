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
	return new GoAction(direction);
}

Action* ActionFactory::createOpenAction()
{
	return new OpenAction();
}

Action* ActionFactory::createInventoryAction()
{
	return new InventoryAction();
}


Action* ActionFactory::createDropAction(common_defs::tokens item)
{
	return new DropAction(item);
}

Action* ActionFactory::createTakeAction(common_defs::tokens item)
{
	return new TakeAction(item);
}

Action* ActionFactory::createCheckAction(common_defs::tokens item)
{
	return new CheckAction(item);
}

Action* ActionFactory::createAttackAction(common_defs::tokens enemy)
{
	return new AttackAction(enemy);
}

Action* ActionFactory::createPutAction(common_defs::tokens item, common_defs::tokens container)
{
	return new PutAction(item,container);
}
