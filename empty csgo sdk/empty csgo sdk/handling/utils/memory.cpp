#include "memory.h"

#include <Windows.h>

namespace handling {
	namespace memory {
		void* ScanInterface(const char* ModuleName, const char* InterfaceName) noexcept {
			const auto module_handle = GetModuleHandleA(ModuleName);

			if (!module_handle)
				return nullptr;

			const auto create_interface_fn = reinterpret_cast<void* (*)(const char*, int*)>(GetProcAddress(module_handle, "CreateInterface"));

			if (!create_interface_fn)
				return nullptr;

			const auto interface_address = create_interface_fn(InterfaceName, nullptr);

			if (!interface_address)
				return nullptr;

			return interface_address;
		}
	};
};