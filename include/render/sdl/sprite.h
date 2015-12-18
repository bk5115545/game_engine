#pragma once

#include <memory>

#include "virtual/component.h"
#include "render/sdl/actor_2d.h"
#include "render/sdl/sdl_renderer.h"
#include "render/sdl/sdl_texture.h"

class SDLRenderer;

class Sprite : public Component {
protected:
    Actor2D* owner_;
    SDLTexture* texture_;
    SDLRenderer* renderer_;
    SDL_Rect sprite_clip_;

public:
    Sprite(Actor2D*);
    ~Sprite();
    void Initialize(SDLRenderer*, SDLTexture*);
    void Update(std::shared_ptr<void> delta_time);
    void Draw();
};
