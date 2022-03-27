#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"


/*
class DropBomb {
    Plane* pPlane;
    DynamicObject* dobj;
    uint16_t* bombsNumber;
public:
    DropBomb()
};
*/

class Command {
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

class DeleteDynamicObj : public Command {
    DynamicObject* dobj;
    std::vector<DynamicObject*>& vecDynamicObj_;
public:
    DeleteDynamicObj(DynamicObject* dobj_, std::vector<DynamicObject*>& _vecDynamicObj) : dobj(dobj_), vecDynamicObj_(_vecDynamicObj) {}
    void Execute() override;
};

class DeleteStaticObj : public Command {
    DestroyableGroundObject* dobj;
    std::vector<GameObject*>& vecStaticObj_;
public:
    DeleteStaticObj(DestroyableGroundObject* dobj_, std::vector<GameObject*>& _vecStaticObj) : dobj(dobj_), vecStaticObj_(_vecStaticObj) {}
    void Execute() override;
};

class DropBomb : public Command {
    Plane* pPlane;
    std::vector<DynamicObject*>& vecDynamicObj_;
    uint16_t& bombsNumber;
    int16_t& score;
public:
    DropBomb(Plane* pPlane_, std::vector<DynamicObject*>& _vecDynamicObj, uint16_t& bombsNumber_ , int16_t&score_) : pPlane(pPlane_), vecDynamicObj_(_vecDynamicObj), bombsNumber(bombsNumber_), score(score_){}
    void Execute() override;
};

class DropDecBomb : public Command {
    Plane* pPlane;
    std::vector<DynamicObject*>& vecDynamicObj_;
    uint16_t& bombsNumber;
    int16_t& score;
public:
    DropDecBomb(Plane* pPlane_, std::vector<DynamicObject*>& _vecDynamicObj, uint16_t& bombsNumber_, int16_t& score_) : pPlane(pPlane_), vecDynamicObj_(_vecDynamicObj), bombsNumber(bombsNumber_), score(score_) {}
    void Execute() override;
};

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();
    void CommandExecuter(Command* pCommand) {
        pCommand->Execute();
    }

private:
    //Command* pcommand;
    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    //void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    //void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    //void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};