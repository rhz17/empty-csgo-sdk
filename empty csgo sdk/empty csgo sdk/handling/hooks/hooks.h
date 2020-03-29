#pragma once

#include "../handling.h"

#include "../utils/vmt.h"

#include "../../sdk/interfaces/interfaces.h"

namespace handling {
	namespace hooks {
		enum funcs_indexes {
			create_move = 24,
			paint_traverse = 41
		};

		static bool __fastcall CreateMoveHook(sdk::interfaces::client_mode* thisptr, std::uint32_t* edx, float Time, sdk::classes::user_cmd* Command) noexcept;
		static void __fastcall PaintTraverseHook(std::uint32_t* ecx, std::uint32_t* edx, std::uint32_t Panel, bool ForceRepaint, bool AllowForce) noexcept;

		typedef bool(__thiscall* CreateMoveT) (sdk::interfaces::client_mode*, std::uint32_t*, float, sdk::classes::user_cmd*) noexcept;
		typedef void(__thiscall* PaintTraverseT) (std::uint32_t*, std::uint32_t, bool, bool) noexcept;

		void RunHooks(void) noexcept;
		void ShutdownHooks(void) noexcept;
	};
};