#pragma once

#include<string>

namespace nano {
	namespace ecs {
		class Entity;
	}
}

namespace nano { namespace engine {  

	struct ScriptCommand {
		std::string commandString;
		std::string arg;
	};

	struct ScriptLogicExpression {
		std::string logicString;
		std::string args;
		ScriptCommand command;
	};

	struct ScriptVariable {
		std::string name;
		std::string value;
	};
} }