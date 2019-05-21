#pragma once
#include "EmptyAction.h"
#include "InvalidAction.h"
#include "LookAction.h"
#include "HelpAction.h"
#include "InventoryAction.h"
#include "GoAction.h"
#include "OpenAction.h"
#include "DropAction.h"
#include "TakeAction.h"
#include "CheckAction.h"
#include "AttackAction.h"
#include "PutAction.h"

static class ActionFactory {
public:
	static Action* createEmptyAction();
	static Action* createInvalidAction();

	static Action* createLookAction();
	static Action* createHelpAction();
	static Action* createInventoryAction();

	static Action* createGoAction(common_defs::tokens direction);
	static Action* createOpenAction(common_defs::tokens item);
	static Action* createDropAction(common_defs::tokens item);
	static Action* createTakeAction(common_defs::tokens item);
	static Action* createCheckAction(common_defs::tokens item);
	static Action* createAttackAction(common_defs::tokens enemy);

	static Action* createOpenAction(common_defs::tokens item, common_defs::tokens opener);
	static Action* createPutAction(common_defs::tokens item, common_defs::tokens container);

};

