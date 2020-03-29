#pragma once

#include "../../sdk/interfaces/interfaces.h"

namespace handling {
	namespace utils {
		class netvar_tree {
			struct node;
			using map_type = std::unordered_map <std::string, std::shared_ptr <node> >;

			struct node {
				node(std::int32_t offset) : offset(offset) { }
				map_type nodes;
				std::int32_t offset;
			};

			map_type nodes;

		public:
			netvar_tree();

			template<typename ...args_t>
			std::int32_t GetOffset(const char* name, args_t ...args) {
				const auto& node = nodes[name];
				return this->GetOffsetRecursive(node->nodes, node->offset, args...);
			}
		private:
			static std::int32_t GetOffsetRecursive(map_type& map, std::int32_t acc, const char* name) {
				return acc + map[name]->offset;
			}

			template<typename ...args_t>
			std::int32_t GetOffsetRecursive(map_type& map, std::int32_t acc, const char* name, args_t ...args) {
				const auto& node = map[name];
				return this->GetOffsetRecursive(node->nodes, acc + node->offset, args...);
			}

			void PopulateNodes(sdk::classes::recv_table* recv_table, map_type* map_type);
		};

		extern std::unique_ptr <netvar_tree> Netvar;
	};
};