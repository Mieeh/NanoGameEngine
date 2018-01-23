#pragma once

// Classes from core
#include<graphics\GraphicsInclude.h>
#include<math\MathInclude.h>
#include<CoreConfig.h>
#include<Clock.h>

// Editor classes
#include"systems\WindowSystem.h"
#include"systems\EntityManagerSystem.h"
#include"systems\RendererSystem.h"
#include"systems\EditorWidgetSystem.h"

namespace nano { namespace editor { 

	class EditorCore {
	private:
		// Editor systems 
		WindowSystem *m_windowSystem;
		EntityManagerSystem *m_entityManagerSystem;
		RendererSystem *m_rendererSystem;
		EditorWidgetSystem *m_editorWidgetSystem;
		CoreConfig *m_config;

		// Other
		Clock m_fpsClock;

	public:
		// Default constructor
		EditorCore();

		// Destructor
		~EditorCore();

		// Initialize the editor
		void Init();

		// Main editor loop this is the root of the program
		void MainLoop();
	};

} } 