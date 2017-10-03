#include "SDK.h"
#include "Menu.h"

/* originals */
OverrideViewFn oOverrideView;
FrameStageNotifyFn oFrameStageNotify;
CreateMoveFn oCreateMove;
PlaySoundFn oPlaySound;
EndSceneFn oEndScene;
ResetFn oReset;
WNDPROC oWndProc;

/* pointers / resolved externs */
settings_t g_Settings;
CMenu* g_pMenu = new CMenu();

/* variables */
bool initialized = false;

void __stdcall HookManager::OverrideView(CViewSetup* vsView)
{
	oOverrideView(vsView);
}

void __stdcall HookManager::FrameStageNotify(ClientFrameStage_t stage)
{
	oFrameStageNotify(stage);
}

bool __stdcall HookManager::CreateMove(float flInputSampleTime, CUserCmd* cmd)
{
	return false;
}

void __stdcall HookManager::PlaySoundG(const char* fileName)
{
	oPlaySound(fileName);
}

long __stdcall HookManager::EndScene(IDirect3DDevice9* device)
{
	static bool done = false;

	if (!done)
	{
		g_pUtils->Log(" Initializing drawing manager and allocating fonts...");
		g_pDraw->Init(device);

		ImGui_ImplDX9_Init(g_Globals::hwndWindow, device);

		g_pMenu->InitializeTheme();

		done = initialized = true;
	}

	/* reset here apparently */
	g_pDraw->Reset();

	DWORD dwOld_D3DRS_COLORWRITEENABLE;

	device->GetRenderState(D3DRS_COLORWRITEENABLE, &dwOld_D3DRS_COLORWRITEENABLE);
	device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xffffffff);

	// If you're doing ESP in EndScene, I suggest doing it here.
	// e.g: g_pESP->Think();

	ImGui_ImplDX9_NewFrame();

	g_pDraw->String(8, 8, FONT_LEFT, g_pDraw->fonts.esp, true, WHITE(255), CHEAT_NAME);
	g_pDraw->String(8, 20, FONT_LEFT, g_pDraw->fonts.esp_small, true, WHITE(255), "%s", __DATE__);

	g_pMenu->Think();

	ImGuiStyle &style = ImGui::GetStyle();

	/* dope animation for pImGui menu */
	if (g_pMenu->m_opened)
	{
		if (style.Alpha > 1.f)
			style.Alpha = 1.f;
		else if (style.Alpha != 1.f)
			style.Alpha += 0.01f; 
	}
	else
	{
		if (style.Alpha < 0.f)
			style.Alpha = 0.f;
		else if (style.Alpha != 0.f)
			style.Alpha -= 0.01f;
	}

	ImGui::Render();

	device->SetRenderState(D3DRS_COLORWRITEENABLE, dwOld_D3DRS_COLORWRITEENABLE);

	return oEndScene(device);
}

long __stdcall HookManager::Reset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	if(!initialized)
		return oReset(pDevice, pPresentationParameters);

	ImGui_ImplDX9_InvalidateDeviceObjects();

	auto res = oReset(pDevice, pPresentationParameters);

	ImGui_ImplDX9_CreateDeviceObjects();

	return res;
}

extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT __stdcall HookManager::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	/* this doesn't really have to go here, i just put it here for convenience */
	g_pMenu->ThinkKeyboard();

	/* blocks input to CSGO and points to ImGui */
	if (initialized && g_pMenu->m_opened && ImGui_ImplDX9_WndProcHandler(hWnd, uMsg, wParam, lParam))
	{
		return true;
	}

	return CallWindowProcA(oWndProc, hWnd, uMsg, wParam, lParam);
}