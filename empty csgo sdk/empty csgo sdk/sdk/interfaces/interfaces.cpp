#include "interfaces.h"

#include "../../handling/utils/memory.h"

namespace sdk {
	namespace interfaces {
		app_system*			AppSystem = nullptr;
		gui_surface*		GuiSurface = nullptr;
		base_client_dll*	ClientDll = nullptr;
		global_vars*		Vars = nullptr;
		client_mode*		ClientMode = nullptr;
		engine_client*		EngineClient = nullptr;
		gui_panel*			GuiPanel = nullptr;

		// Initialize interfaces
		void RunInterfaces(void) noexcept {
			GuiSurface = reinterpret_cast <gui_surface*> (handling::memory::ScanInterface("vguimatsurface.dll", "VGUI_Surface031"));
			ClientDll = reinterpret_cast <base_client_dll*> (handling::memory::ScanInterface("client_panorama.dll", "VClient018"));

			Vars = **reinterpret_cast <global_vars***> ((*reinterpret_cast <uintptr_t**> (ClientDll))[11] + 10);
			ClientMode = **reinterpret_cast <client_mode***> ((*reinterpret_cast <uintptr_t**> (ClientDll))[10] + 5);

			EngineClient = reinterpret_cast <engine_client*> (handling::memory::ScanInterface("engine.dll", "VEngineClient014"));
			GuiPanel = reinterpret_cast <gui_panel*> (handling::memory::ScanInterface("vgui2.dll", "VGUI_Panel009"));
		}

		// Invalidate interfaces when finalizing
		void ShutdownInterfaces(void) noexcept {
			AppSystem = nullptr;
			GuiSurface = nullptr;
			ClientDll = nullptr;
			Vars = nullptr;
			ClientMode = nullptr;
			EngineClient = nullptr;
			GuiPanel = nullptr;
		}
	}
};