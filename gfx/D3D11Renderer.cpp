#include "D3D11Renderer.h"
#include "../cwsdk.h"

void gfx::D3D11Renderer::RemeshZone(int x, int y) {
    ((void(*)(gfx::D3D11Renderer*, int, int))CWOffset(0xE9530))(this, x, y);
}

void gfx::D3D11Renderer::CW_DB630(cube::Creature::AnimationState* animation_state, float x, float y)
{
    ((void (*)(gfx::D3D11Renderer*, cube::Creature::AnimationState*, float, float))CWOffset(0xDB630))(this, animation_state, x, y);
}
