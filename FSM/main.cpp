#include "Locations.h"
#include "Miner.h"
#include "MinersWife.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "EntityNames.h"


int main()
{
	Miner* miner = new Miner(ent_Miner_Bob);
	
	MinersWife* wife = new MinersWife(ent_Elsa);

	EntityMgr->RegisterEntity(miner);
	EntityMgr->RegisterEntity(wife);

	for (int i = 0; i < 23; ++i)
	{
		miner->Update();
		wife->Update();
		Dispatch->DispatchDelyedMessage();
	}

	delete miner;
	delete wife;

	return 0;
}