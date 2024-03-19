namespace Globals {
    static SDK::UHottaGameEngine *engine = nullptr;

    SDK::UHottaGameEngine *getEngine() {
        if (engine == nullptr) {
            engine = (SDK::UHottaGameEngine *)SDK::UEngine::GetEngine();
        }

        return engine;
    }

    SDK::UGameInstance *getInstance() {
        if (getEngine() != nullptr) {
            return engine->GameInstance;
        }

        return nullptr;
    }

    SDK::UHottaLocalPlayer *getLocalPlayer() {
        if (getInstance() != nullptr) {
            const auto localPlayers = getInstance()->LocalPlayers;

            if (localPlayers.Num() > 0) {
                return (SDK::UHottaLocalPlayer *)localPlayers[0];
            }
        }

        return nullptr;
    }

    SDK::UWorld *getWorld() {
        if (getEngine() != nullptr) {
            if (getEngine()->GameViewport != nullptr) {
                return getEngine()->GameViewport->World;
            }
        }

        return nullptr;
    }

    SDK::AQRSLPlayerCharacter *getCharacter() {
        const auto localPlayer = getLocalPlayer();

        if (localPlayer == nullptr) {
            return nullptr;
        }

        if (localPlayer->PlayerController == nullptr) {
            return nullptr;
        }

        const auto character = (SDK::AQRSLPlayerCharacter *)localPlayer->PlayerController->Character;

        return character;
    }
} // namespace Globals