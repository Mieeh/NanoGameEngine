#pragma once

#include"WindowSystem.h"
#include"AssetSystem.h"
#include"WorldSystem.h"
#include"InputSystem.h"
#include"RendererSystem.h"
#include"LevelSystem.h"
#include"EngineConfig.h"

#include<Clock.h>

namespace nano { namespace engine {  

class EngineCore {

public:
	// Constructor
	EngineCore();

	// Destructor
	~EngineCore();

	// Initalize engine
	void init();

	// Shutdown engine
	void shutdown();

	// Main engine loop, root of the program
	void mainLoop();
	void fixedLoop();

private:
	EngineConfig *m_engineConfig;
	// Window System
	WindowSystem *m_windowSystem;
	AssetSystem *m_assetSystem;
	InputSystem *m_inputSystem;
	WorldSystem *m_worldSystem;
	LevelSystem *m_levelSystem;
	RendererSystem *m_rendererSystem;
	// Delta-timer Clock
	Clock m_deltaTimer;
};

} }