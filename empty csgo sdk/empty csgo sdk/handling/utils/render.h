#pragma once

#include "../handling.h"

namespace handling {
	namespace utils {
		extern std::uint64_t GeneralFont;

		void RenderLine(std::int32_t x, std::int32_t y, std::int32_t x2, std::int32_t y2, sdk::classes::color color);
		void RenderText(std::int32_t x, std::int32_t y, sdk::classes::color color, std::uint64_t font, std::string_view text);

		void RunRender(void) noexcept;
		void ShutdownRender(void) noexcept;
	};
};