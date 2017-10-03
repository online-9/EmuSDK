#pragma once
#include "SDK.h"

struct settings_t
{
	struct
	{
		bool Your_Settings_Here; 
	}Example;

}; extern settings_t g_Settings;

class CMenu
{
public:
	void ThinkKeyboard()
	{
		static bool PressedButtons = false;

		if (!PressedButtons && GetAsyncKeyState(VK_DELETE))
		{
			PressedButtons = true;
		}
		else if (PressedButtons && !GetAsyncKeyState(VK_DELETE))
		{
			PressedButtons = false;
			m_opened = !m_opened;
		}
	}

	void SelectedTab()
	{
		ImGuiStyle& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_Button] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
	}

	void NormalTab()
	{
		ImGuiStyle& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
	}

	void InitializeTheme()
	{
		ImGuiStyle& style = ImGui::GetStyle();

		style.FramePadding = ImVec2(4, 2);
		style.ItemSpacing = ImVec2(6, 2);
		style.ItemInnerSpacing = ImVec2(6, 4);
		style.Alpha = 0.0f;
		style.WindowRounding = 4.0f;
		style.WindowTitleAlign = ImVec2(0.5, 0.5);
		style.FrameRounding = 2.0f;
		style.IndentSpacing = 6.0f;
		style.ItemInnerSpacing = ImVec2(2, 4);
		style.ColumnsMinSpacing = 50.0f;
		style.GrabMinSize = 14.0f;
		style.GrabRounding = 16.0f;
		style.ScrollbarSize = 12.0f;
		style.ScrollbarRounding = 16.0f;

		style.Colors[ImGuiCol_Text] = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
		style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
		style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
		style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.58f);
		style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.00f);
		style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_TitleBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
		style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
		style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_ComboBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
		style.Colors[ImGuiCol_CheckMark] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
		style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
		style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.86f);
		style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_Header] = ImVec4(0.15f, 0.60f, 0.78f, 0.76f);
		style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.0f); // 
		style.Colors[ImGuiCol_Column] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
		style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
		style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.15f, 0.60f, 0.78f, 0.78f);
		style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_CloseButton] = ImVec4(0.86f, 0.93f, 0.89f, 0.16f);
		style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.86f, 0.93f, 0.89f, 0.39f);
		style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
		style.Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
		style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
		style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.15f, 0.60f, 0.78f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.15f, 0.60f, 0.78f, 0.43f);
		style.Colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.22f, 0.27f, 0.9f);
		style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 0.73f);
	}

	void Think()
	{
		static bool last = m_opened;

		if (m_opened != last)
		{
			last = m_opened;

			std::string msg = ("cl_mouseenable ") + std::to_string(!m_opened);
			g_pEngine->ExecuteClientCmd(msg.c_str());
		}

		ImGui::GetIO().MouseDrawCursor = m_opened;

		/* your dope imgui menu here */
		ImGui::Begin(CHEAT_NAME, &m_opened, ImVec2(600, 350), 0.9f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		{
			
		}
		ImGui::End();
	}


	bool m_opened = false;
}; extern CMenu* g_pMenu;
