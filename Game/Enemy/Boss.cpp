#include "Boss.h"


Boss::Boss(GamePlaingScene* gm):gameScene(gm),Enemy(gm->GetPlayer(),gm->GetCamera())
{
}
