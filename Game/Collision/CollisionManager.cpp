#include "CollisionManager.h"
#include <algorithm>
#include "Collider.h"
#include "../Character.h"
#include <DxLib.h>
#include"../../System/Debugger.h"
#include "../Enemy/BossShot.h"

namespace {
    bool keyF1Pressed = false;
    bool debugDisp_ = false;
    std::pair<std::string, std::string> hit_conbination_table[] = { 
        {"edmg","patk"}, {"bdmg","patk"},{"eblt","patk"}, {"play","eblt"}
    };
}


void CollisionManager::FalseImmortal()
{
    for (auto& col : colliders_)
    {
        if (col->isImmortal_ == true)
        {
            col->isImmortal_=false;
            col->Suicide();
        }
    }
}

int& CollisionManager::GetBossLife()
{
    return bossLife_;
}


void CollisionManager::AddColliders(Collider* c)
{
        colliders_.emplace_back(c);
 }

void CollisionManager::Update()
{
    if (CheckHitKey(KEY_INPUT_F1))
    {
        debugDisp_ = !debugDisp_;
    }
    auto it = remove_if(colliders_.begin(), colliders_.end(),
        [](std::shared_ptr<Collider>& col) {
            return col->OwnerIsDead() || col->IsDead();
        });
    colliders_.erase(it, colliders_.end());
    for (auto& colA : colliders_) {
        if (colA->IsDead() || colA->OwnerIsDead())continue;
        for (auto& colB : colliders_) {
            if (colB->IsDead() || colB->OwnerIsDead())continue;
            if (colA == colB) {
                continue;
            }
            auto c = std::count(std::begin(hit_conbination_table), 
                std::end(hit_conbination_table), 
                std::make_pair(colA->GetTag(), colB->GetTag()));
            if (c == 0)continue;

            if (colA->IsHit(colB)|| colB->IsHit(colA)) {
                
                int retflag;
                TagCheck(colA, colB, retflag,"bdmg");
                if (retflag == 3) continue;
                TagCheck(colA, colB, retflag, "play");
                if (retflag == 3) continue;



                CollisionInfo colInfoB = { colB };
                CollisionInfo colInfoA = { colA };
                colA->GetOwner()->OnHit(colInfoB, colInfoA);
                colA->Suicide();
                colB->GetOwner()->OnHit(colInfoA, colInfoB);
                colB->Suicide();
            }
        }
    }
}

void CollisionManager::TagCheck(std::shared_ptr<Collider>& colA, std::shared_ptr<Collider>& colB, int& retflag,std::string tag)
{
    retflag = 1;
    if (colA->GetTag() == tag || colB->GetTag() == tag) {
        CollisionInfo colInfoB = { colB };
        CollisionInfo colInfoA = { colA };
        colA->GetOwner()->OnHit(colInfoB, colInfoA);
        colB->GetOwner()->OnHit(colInfoA, colInfoB);
        if (colA->GetTag() != tag) {
            colA->Suicide();
        }
        if (colB->GetTag() != tag) {
            colB->Suicide();
        }
        if (bossLife_ != 0) {
            { retflag = 3;};
        }
    }
}

void CollisionManager::DebagDraw()
{
    if (!Debugger::Instance().IsDebugMode())return;
    for (auto& c : colliders_)
    {
        c->Draw();
    }
    DrawFormatString(300, 30, 0xffffff, L"コライダー数=%d", colliders_.size());
}

