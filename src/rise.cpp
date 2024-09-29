#include "rise.hpp"

#include <tyra>

namespace Rise {

    using namespace Tyra;

    RiseGame::RiseGame(Engine* t_engine) {
        engine = t_engine;
    }

    RiseGame::~RiseGame() {

        engine->renderer.getTextureRepository().freeBySprite(title);        
        engine->renderer.getTextureRepository().freeBySprite(background);
        engine->renderer.getTextureRepository().freeBySprite(newgame);
        engine->renderer.getTextureRepository().freeBySprite(settings);
        engine->renderer.getTextureRepository().freeBySprite(credits);
        engine->renderer.getTextureRepository().freeBySprite(hyphen);

    }

    void RiseGame::init() {

        engine->renderer.setClearScreenColor(Color(222.0F, 222.0F, 222.0F));
        loadSprite(&background, "ui/menuBackground.png", 0.0f, 0.0f, 512.0f, 512.0f);
        loadSprite(&title, "ui/title.png", 0.0f, 25.0f, 512.0f, 128.0f);
        loadSprite(&newgame, "ui/newgame.png", 55.0f, 175.0f, 256.0f, 64.0f);
        loadSprite(&settings, "ui/settings.png", 55.0f, 235.0f, 256.0f, 64.0f);
        loadSprite(&credits, "ui/credits.png", 55.0f, 300.0f, 256.0f, 64.0f);
        loadSprite(&hyphen, "ui/hyphen.png", 0.0f, 175.0f, 64.0f, 64.0f);

    }

    void RiseGame::loop() {

        auto& renderer = engine->renderer;

        renderer.beginFrame();

        renderer.renderer2D.render(background);
        renderer.renderer2D.render(title);
        renderer.renderer2D.render(newgame);
        renderer.renderer2D.render(settings);
        renderer.renderer2D.render(credits);
        renderer.renderer2D.render(hyphen);

        renderer.endFrame();
    }

    void RiseGame::loadSprite(Tyra::Sprite* sprite, const char filename[], float x, float y, float w, float h) {

        const auto& screenSettings = engine->renderer.core.getSettings();

        sprite->mode = SpriteMode::MODE_STRETCH;
        sprite->size = Vec2(w, h);
        sprite->position = Vec2(x, y);

        auto& renderer = engine->renderer;
        auto& textureRepository = renderer.getTextureRepository();
        auto filepath = FileUtils::fromCwd(filename);

        auto* texture = textureRepository.add(filepath);
        texture->addLink(sprite->id);
    }

}
