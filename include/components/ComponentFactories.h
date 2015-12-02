#pragma once

#include <memory>
#include <string>

#include "Box2D/Box2D.h"
#include "core/PugiXML/pugixml.hpp"

#include "art_library/ArtAssetLibrary.h"

#include "components/Animation.h"
#include "components/Bullet.h"
#include "components/Carrier.h"
#include "components/Infantry.h"
#include "components/Player.h"


#include "core/input_device.h"
#include "render/sdl/sprite.h"
#include "core/Physics.h"

#include "virtual/component.h"

class ComponentFactory {
protected:

public:
    ComponentFactory();
    virtual ~ComponentFactory() = 0;
    virtual Component* Create(Actor*, pugi::xml_node) = 0;
};

class CarrierFactory : ComponentFactory {
protected:
public:
    CarrierFactory();
    ~CarrierFactory();
    Carrier* Create(Actor*, pugi::xml_node);
};

class InfantryFactory : ComponentFactory {
protected:
public:
    InfantryFactory();
    ~InfantryFactory();
    Infantry* Create(Actor*, pugi::xml_node);
};

class PlayerFactory : ComponentFactory {
protected:
    InputDevice* input_device_;

public:
    PlayerFactory(InputDevice*);
    ~PlayerFactory();
    Player* Create(Actor*, pugi::xml_node);
};

/*
class RigidCircleFactory : ComponentFactory {
protected:
    b2World* world_;

public:
    RigidCircleFactory(b2World*);
    ~RigidCircleFactory();
    RigidCircle* Create(Actor*, pugi::xml_node);
};
*/

class RigidRectangleFactory : ComponentFactory {
protected:
    b2World* world_;

public:
    RigidRectangleFactory(b2World*);
    ~RigidRectangleFactory();
    RigidRectangle* Create(Actor*, pugi::xml_node);
};

class SpriteFactory : ComponentFactory {
protected:
    Renderer* renderer_;
    ArtAssetLibrary* art_library_;

public:
    SpriteFactory(Renderer*, ArtAssetLibrary*);
    ~SpriteFactory();
    Sprite* Create(Actor*, pugi::xml_node);
};

class AnimationFactory : ComponentFactory {
protected:


public:
    AnimationFactory();
    ~AnimationFactory();
    Animation* Create(Actor*, pugi::xml_node);
};