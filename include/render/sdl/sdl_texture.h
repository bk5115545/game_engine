#pragma once

#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "util/definitions.h"
#include "render/sdl/sdl_camera.h"

class SDLTexture {
protected:
    SDL_Texture* texture_;
    SDL_Renderer* renderer_;
    SDLCamera* camera_;

public:
    SDLTexture();
    ~SDLTexture();
    bool Initialize(SDL_Renderer*, SDLCamera*, std::string);
    void Render(Vector2, float32, SDL_Rect);
    // void Render(Vector2, float32);
    void GetDimensions(int32*, int32*);
};
