#include "netvar.h"

namespace handling {
	namespace utils {
		netvar_tree::netvar_tree() {
			const sdk::classes::client_class* client_class = sdk::interfaces::ClientDll->GetAllClasses();

			while (client_class != nullptr) {
				const auto class_info = std::make_shared<node>(0);
				sdk::classes::recv_table* recv_table = client_class->recvtable_ptr;

				this->PopulateNodes(recv_table, &class_info->nodes);
				nodes.emplace(recv_table->table_name, class_info);

				client_class = client_class->next_ptr;
			}
		}

		void netvar_tree::PopulateNodes(sdk::classes::recv_table* recv_table, map_type* map_type) {
			for (auto i = 0; i < recv_table->props_count; i++) {
				const sdk::classes::recv_prop* prop = recv_table->get_prop(i);
				const auto propInfo = std::make_shared < node >(prop->offset);

				if (prop->prop_type == sdk::classes::send_prop_type::_data_table)
					this->PopulateNodes(prop->data_table, &propInfo->nodes);

				map_type->emplace(prop->prop_name, propInfo);
			}
		}

		std::unique_ptr <netvar_tree> Netvar;
	};
};