#include"../include/widgets/MenuBarWidget.h"

#include<CoreConfig.h>
#include<iostream>

#include"../include/DearImGui/imgui.h"

#include"../include/systems/WorldSystem.h"
#include"../include/systems/EditorWidgetSystem.h"

namespace nano { namespace editor {

	MenuBarWidget::MenuBarWidget()
	{
	}

	void MenuBarWidget::Start()
	{
		// Getting acess to the config file
		m_config = CoreConfig::Instance();
		m_showCreditsWidget = false;
	}

	void MenuBarWidget::Update()
	{

	}

	void MenuBarWidget::Render()
	{
		if (ImGui::BeginMainMenuBar()) 
		{

			if (ImGui::BeginMenu("File")) 
			{
				if (ImGui::Selectable("Save Level")) {

				}
				if (ImGui::Selectable("Load Level")) {

				}

				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Invoke")) 
			{
				if (ImGui::Selectable("Compile & Run")) {

				}
				if (ImGui::Selectable("Compile")) {

				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("About")) {
				if (ImGui::Selectable("Version")) {

				}
				if (ImGui::Selectable("Credit")) {
					m_showCreditsWidget = true;
				}
				ImGui::EndMenu();
			}
			if (ImGui::BeginMenu("Entity"))
			{
				if (ImGui::Selectable("Create New")) {
					WorldSystem::Instance()->CreateNewEntity("unnamed");
					// Test case!
					// Send this event to the event handler!
					EditorWidgetSystem::Instance()->GetEventHandler().AddEvent(BaseEvent(EventTypes::CREATED_ENTITY, "unnamed"));
				}
				ImGui::EndMenu();
			}

			ImGui::EndMainMenuBar();
		}

		if (m_showCreditsWidget) {
			ImGui::Begin("Credits", &m_showCreditsWidget, ImVec2(300, 200), 1.0f, ImGuiWindowFlags_::ImGuiWindowFlags_NoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse);
			ImGui::Text("Programmer: David Styrbj�rn");
			ImGui::Text("License: GNU General Public License v3.0");
			ImGui::End();
		}
	}
}
}