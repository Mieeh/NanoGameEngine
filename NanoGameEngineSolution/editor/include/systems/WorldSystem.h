#pragma once

#include"EditorSystem.h" // base class

#include<vector>
#include<ecs\Entity.h>

namespace nano { namespace editor {
	
	/*
	*
	* std::vector<Entity*> m_entitiesToManage;
	* void AddNewEntity(Entity* a_entityToAdd);
	* std::vector<Entity*>& GetEntityList();
	*
	*/

	#define MAX_ENTITIES 500

	class WorldSystem : public EditorSystem<WorldSystem> {
		friend class EditorSystem<WorldSystem>;
	private:
		// Private Constructor (singleton)
		WorldSystem() { }

	private:
		// New
		int m_entityCount;
		ecs::Entity m_entityArray[MAX_ENTITIES];

	public:
		void LoadedNewLevel(std::vector<ecs::Entity*> a_entityList); // Called when a new level is loaded

		// New
		int createNewEntity(std::string a_name);
		void removeEntity(int a_index);
		ecs::Entity& getEntity(int a_index);
		std::vector<ecs::Entity> getArray();

		// EditorSystem base class
		void Start() override;
		void Update() override;
		void FixedUpdate() override;
		void Quit() override;
	};
	
} }