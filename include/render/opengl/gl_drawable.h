#pragma once

#include "virtual/component.h"

Class GlDrawable : Component {
protected:
    GlModel* model_;

public:
    GlDrawable();
    ~GlDrawable();
    
    void Draw();
}