#include "virtual/component.h"

Component::Component(Actor* owner) {
    owner_ = owner;
}

Component::~Component() {
    //needed for virtual overrides
}