#include "AnimatedTexture.h"

#include <ratio>

#include "Point.h"
#include "Rect.h"
#include "Renderer.h"
#include "Size.h"
#include "Surface.h"
#include "Texture.h"

namespace RescueHim {
    namespace Sdl {
        AnimatedTexture::AnimatedTexture(const Renderer& renderer, const Surface& surface, Geom::Size frameSize, int numFrames, clock::duration frameDuration)
            : Texture(renderer, surface)
            , frameSize{frameSize}
            , numFrames{numFrames}
            , frameDuration{frameDuration}
            , currentFrame{0}
            , currentRect{{0, 0}, frameSize}
        {            
        }
        
        Geom::Size AnimatedTexture::getSize() const {
            return frameSize;
        }
        
        //void AnimatedTexture::draw(const Renderer& renderer, Geom::Point dest) {
        void AnimatedTexture::draw(Geom::Point dest) {
            auto time_since_last_update = clock::now() - lastTime;
            
            if (time_since_last_update >= frameDuration) {
                // neuen malen
                currentFrame++;
                
                if (currentFrame == numFrames) {
                    currentFrame = 0;
                    currentRect = {{0, 0}, frameSize};
                } else {
                    currentRect.offsetBy({static_cast<int>(frameSize.width), 0});
                }
                
                // Aktuelle Zeit merken
                lastTime = clock::now();                
            }
            
            // Frame blitten
            const_cast<Renderer&>(renderer).copy(*this, currentRect, {dest, getSize()});
        }
    }
}
