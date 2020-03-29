#pragma once

#include <Windows.h>
#include <assert.h>
#include <stdio.h>
#include <map>
#include <cstdint>
#include <stdexcept>
#include <memory>

#define NOMINMAX

namespace handling {
	namespace utils {
		namespace detail {
			class protect_guard {
			public:
				protect_guard(void* base, size_t len, std::uint32_t flags) {
					_base = base;
					_length = len;
					if (!VirtualProtect(base, len, flags, (PDWORD)&_old))
						throw std::runtime_error("failed to protect region.");
				}
				~protect_guard() {
					VirtualProtect(_base, _length, _old, (PDWORD)&_old);
				}
			private:
				void* _base;
				size_t _length;
				std::uint32_t _old;
			};
		}

		class vmt_hook {
		private:
			static inline std::size_t estimate_vftbl_length(std::uintptr_t* vftbl_start);

			void* class_base;
			std::size_t     vftbl_len;
			std::uintptr_t* new_vftb1;
			std::uintptr_t* old_vftbl;
			LPCVOID         search_base = nullptr;
			bool was_allocated = false;
		public:
			uintptr_t* search_free_data_page(const char* module_name, const std::size_t vmt_size);
			vmt_hook();
			vmt_hook(void* base);
			~vmt_hook();

			bool Initialize(void* base, const char* module_name = nullptr);

			void HookFunction(size_t fn_index, void* fn_pointer);
			void Shutdown();

			void* GetOriginalFunction(size_t fn_index);
		};
	};
};