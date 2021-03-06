#include"../include/systems/EditorWidgetSystem.h"

#include"../include/DearImGui/imgui.h"
#include"../include/DearImGui/imgui_glfw.h"

#include<GLFW\glfw3.h>

#include<iostream>

namespace nano { namespace editor { 

	void EditorWidgetSystem::Start()
	{
		// Create event handler
		m_eventHandler = new EventHandler();
		m_eventHandler->AddEventObserver(&m_entityInspectorWidget);
		m_eventHandler->AddEventObserver(&m_consoleWidget);

		ImGui_ImplGlfwGL3_Init(glfwGetCurrentContext(), false);

		SetupStyle();

		// Call start on widget
		m_menuBarWidget.Start();
		m_consoleWidget.Start();
		
		m_assetBrowserWidget.Start();
		m_utilityWidget.Start();

		m_entitySelectWidget.Start();
		m_entityInspectorWidget.Start();
	}

	void EditorWidgetSystem::Update()
	{
		// Update every widget
		m_menuBarWidget.Update();
		m_consoleWidget.Update();

		m_assetBrowserWidget.Update();
		m_utilityWidget.Update();

		m_entitySelectWidget.Update();
		m_entityInspectorWidget.Update();
	}

	void EditorWidgetSystem::Quit()
	{
		ImGui_ImplGlfwGL3_Shutdown();
		delete m_eventHandler;
		std::cout << "Editor Widget system quit correctly" << std::endl;
	}

	void EditorWidgetSystem::Begin()
	{
		// Tell ImGui we're now on a new frame
		ImGui_ImplGlfwGL3_NewFrame();
	}

	void EditorWidgetSystem::Flush()
	{
		// Tell every widget to render their shit
		m_menuBarWidget.Render();

		if (m_renderWidgets) {
			m_consoleWidget.Render();
			m_assetBrowserWidget.Render();
			m_utilityWidget.Render();
			m_entitySelectWidget.Render();
			m_entityInspectorWidget.Render();
		}

		// Tell ImGui to render 
		ImGui::Render();
	}

	bool EditorWidgetSystem::GetRenderWidgets()
	{
		return m_renderWidgets;
	}

	void EditorWidgetSystem::SetRenderWidgets(bool a_value)
	{
		m_renderWidgets = a_value;
	}

	EventHandler & EditorWidgetSystem::GetEventHandler()
	{
		return *m_eventHandler;
	}

	void EditorWidgetSystem::SetupStyle()
	{
		//ImGuiIO &io = ImGui::GetIO();
		
		//io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arial.ttf", 12);
		//io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arial.ttf", 10);
		//io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arial.ttf", 14);
		//io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arial.ttf", 18);		

		ImGuiStyle& style = ImGui::GetStyle();

		// light style from Pac�me Danhiez (user itamago) https://github.com/ocornut/imgui/pull/511#issuecomment-175719267
		style.Alpha = 1.0f;
		style.FrameRounding = 3.0f;
		style.WindowRounding = 0.0f;

		style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
		style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.94f);
		style.Colors[ImGuiCol_Border] = ImVec4(1.00f, 1.00f, 1.00f, 0.39f);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.10f);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.6f, 0.00f, 0.00f, 0.94f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.8f, 0.00f, 0.00f, 0.94f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.9f, 0.0f, 0.0f, 0.94f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.24f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.24f, 0.00f, 0.00f, 0.51f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.24f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		style.Colors[ImGuiCol_ComboBg] = ImVec4(0.14f, 0.14f, 0.14f, 0.99f);
		style.Colors[ImGuiCol_CheckMark] = ImVec4(0.73f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.43f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.73f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.44f, 0.00f, 0.00f, 0.40f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.73f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_Header] = ImVec4(0.79f, 0.00f, 0.00f, 0.31f);
		style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.80f, 0.00f, 0.00f, 0.80f);
		style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.78f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_Column] = ImVec4(0.95f, 0.00f, 0.61f, 1.00f);
		style.Colors[ImGuiCol_ColumnHovered] = ImVec4(1.00f, 0.00f, 0.29f, 0.78f);
		style.Colors[ImGuiCol_ColumnActive] = ImVec4(1.00f, 0.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.34f, 0.00f, 0.00f, 0.50f);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.00f, 0.00f, 0.67f);
		style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.57f, 0.00f, 0.00f, 0.95f);
		style.Colors[ImGuiCol_CloseButton] = ImVec4(0.48f, 0.00f, 0.01f, 0.50f);
		style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.74f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.19f, 0.00f, 0.35f);
		style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

		//float alpha_ = 1.0f;
		//for (int i = 0; i <= ImGuiCol_COUNT; i++)
		//{
		//	ImVec4& col = style.Colors[i];
		//	float H, S, V;
		//	ImGui::ColorConvertRGBtoHSV(col.x, col.y, col.z, H, S, V);
		//
		//	if (S < 0.1f)
		//	{
		//		V = 1.0f - V;
		//	}
		//	ImGui::ColorConvertHSVtoRGB(H, S, V, col.x, col.y, col.z);
		//	if (col.w < 1.00f)
		//	{
		//		col.w *= alpha_;
		//	}
		//}
	}

} }