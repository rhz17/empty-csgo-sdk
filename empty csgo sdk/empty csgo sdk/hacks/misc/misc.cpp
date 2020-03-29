#pragma once

#include "misc.h"

namespace hacks {
	namespace misc {
		void movement::DuckLimitBypass(void) noexcept {
			handling::utils::Command->Buttons |= sdk::classes::cmd_buttons::in_bullrush;
		}

		void movement::OnEveryFrame(void) noexcept {
			this->DuckLimitBypass();
		}
		
		movement move;
	};
};