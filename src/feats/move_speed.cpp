#include "move_speed.hpp"
#include "imgui.h"

namespace Feats {
    namespace MoveSpeed {
        void tick() {
            if (enabled) {
                const auto world = SDK::UWorld::GetWorld();

                if (world != nullptr) {
                    const auto instance = world->OwningGameInstance;

                    if (instance->LocalPlayers.Num() > 0) {
                        const auto localPlayer = (SDK::UQRSLLocalPlayer *)instance->LocalPlayers[0];

                        const auto character = (SDK::AQRSLPlayerCharacter *)localPlayer->PlayerController->Character;

                        character->ClientSetMaxWalkSpeed(speed);
                    }
                }
            }
        }
        void init() { return; }
        void menu() {
            ImGui::Checkbox("Enabled", &enabled);
            ImGui::SliderFloat("Speed", &speed, 1.0f, 10000.0f);
        }
    } // namespace MoveSpeed
} // namespace Feats