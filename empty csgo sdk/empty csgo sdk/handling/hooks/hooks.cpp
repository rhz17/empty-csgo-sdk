#include "hooks.h"

#include "../utils/render.h"

#include "../../hacks/misc/misc.h"

namespace handling {
	namespace hooks {
		std::unique_ptr <handling::utils::vmt_hook> CModeHook;
		std::unique_ptr <handling::utils::vmt_hook> GPanelHook;

		static bool __fastcall CreateMoveHook(sdk::interfaces::client_mode* thisptr, std::uint32_t* edx, float Time, sdk::classes::user_cmd* Command) noexcept {
			static auto OriginCreateMove = reinterpret_cast <handling::hooks::CreateMoveT> (CModeHook->GetOriginalFunction(handling::hooks::funcs_indexes::create_move));
			
			// Free the engine
			OriginCreateMove(thisptr, edx, Time, Command);

			if(!sdk::interfaces::EngineClient->IsConnected() || !sdk::interfaces::EngineClient->IsInGame())
				return OriginCreateMove(thisptr, edx, Time, Command);

			if (!Time || !Command || !Command->CommandNumber)
				return OriginCreateMove(thisptr, edx, Time, Command);

			// Run variables
			handling::utils::Command = Command;

			// Example
			hacks::misc::move.OnEveryFrame();

			return true;
		}

		static void __fastcall PaintTraverseHook(std::uint32_t* ecx, std::uint32_t* edx, std::uint32_t Panel, bool ForceRepaint, bool AllowForce) noexcept {
			static auto OriginPaintTraverse = reinterpret_cast <handling::hooks::PaintTraverseT> (GPanelHook->GetOriginalFunction(handling::hooks::funcs_indexes::paint_traverse));

			static std::uint32_t PanelID;

			// Free the engine
			OriginPaintTraverse(ecx, Panel, ForceRepaint, AllowForce);

			if (!PanelID) {
				if (!strcmp("MatSystemTopPanel", sdk::interfaces::GuiPanel->GetPanelName(Panel)))
					PanelID = Panel;
			}

			if (PanelID == Panel) {
				// Example
				handling::utils::RenderText(20, 350, sdk::classes::color(255, 255, 255, 255), handling::utils::GeneralFont, "[SDK]: Has been loaded!");
			}
		}

		void RunHooks(void) noexcept {
			CModeHook = std::make_unique <handling::utils::vmt_hook> ();
			CModeHook->Initialize(sdk::interfaces::ClientMode);
			CModeHook->HookFunction(handling::hooks::funcs_indexes::create_move, reinterpret_cast <void*> (handling::hooks::CreateMoveHook));

			GPanelHook = std::make_unique <handling::utils::vmt_hook> ();
			GPanelHook->Initialize(sdk::interfaces::GuiPanel);
			GPanelHook->HookFunction(handling::hooks::funcs_indexes::paint_traverse, reinterpret_cast <void*> (handling::hooks::PaintTraverseHook));
		}

		void ShutdownHooks(void) noexcept {
			CModeHook->Shutdown();
			GPanelHook->Shutdown();
		}
	};
};