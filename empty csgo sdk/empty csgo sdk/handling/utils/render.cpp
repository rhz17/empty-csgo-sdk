#pragma once

#include "render.h"
#include "../../sdk/interfaces/interfaces.h"

namespace handling {
	namespace utils {
		std::uint64_t GeneralFont;

		void RenderLine(std::int32_t x, std::int32_t y, std::int32_t x2, std::int32_t y2, sdk::classes::color color) {
			sdk::interfaces::GuiSurface->DrawSetColor(color.red, color.green, color.blue, color.alpha);
			sdk::interfaces::GuiSurface->DrawLine(x, y, x2, y2);
		}

		void RenderText(std::int32_t x, std::int32_t y, sdk::classes::color color, std::uint64_t font, std::string_view text) {
			const auto FinalText = std::wstring(text.begin(), text.end());

			sdk::interfaces::GuiSurface->DrawSetTextColor(color.red, color.green, color.blue, color.alpha);
			sdk::interfaces::GuiSurface->DrawSetTextFont(font);
			sdk::interfaces::GuiSurface->DrawSetTextPos(x, y);
			sdk::interfaces::GuiSurface->DrawPrintText(FinalText.c_str(), wcslen(FinalText.c_str()));
		}

		void RunRender(void) noexcept {
			GeneralFont = sdk::interfaces::GuiSurface->CreateGuiFont();

			sdk::interfaces::GuiSurface->SetFontGlyphSet(GeneralFont, "Small Fonts", 12, 0, 0, 0, sdk::interfaces::font_flags::fontflag_antialias | sdk::interfaces::font_flags::fontflag_outline);
		}

		void ShutdownRender(void) noexcept {
			GeneralFont = NULL;

			sdk::interfaces::GuiSurface->SetFontGlyphSet(NULL, NULL, NULL, NULL, NULL, NULL, NULL);
		}
	};
};