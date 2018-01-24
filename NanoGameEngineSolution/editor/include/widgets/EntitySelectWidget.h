#pragma once

#include"EditorWidget.h"

// FWD
namespace nano {
	class CoreConfig;
}


namespace nano { namespace editor {  

	class EntitySelectWidget : EditorWidget {
	private:
		CoreConfig* m_config;

	public:
		EntitySelectWidget();

		// Base class 
		void Start() override;
		void Update() override;
		void Render() override;
	};

} }