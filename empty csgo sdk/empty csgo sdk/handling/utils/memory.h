#pragma once

namespace handling {
	namespace memory {
		template <typename T>
		static T ScanVFunction(void* Address, int Index) noexcept {
			return (*reinterpret_cast<T**>(Address))[Index];
		}

		void* ScanInterface(const char* ModuleName, const char* InterfaceName) noexcept;
	};
};