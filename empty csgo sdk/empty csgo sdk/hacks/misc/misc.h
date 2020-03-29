#pragma once

#include "../../handling/utils/variables.h"

namespace hacks {
	namespace misc {
		class movement {
		public:
			void DuckLimitBypass(void) noexcept;
			void OnMove(void) noexcept;
		};

		extern movement move;
	};
};
