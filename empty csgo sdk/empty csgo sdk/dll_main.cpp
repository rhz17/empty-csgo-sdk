#include "sdk/sdk.h"

#include "handling/handling.h"

#include "handling/utils/render.h"
#include "handling/utils/netvar.h"

#include "handling/hooks/hooks.h"

DWORD APIENTRY RunDllHandling(HINSTANCE module_handle) noexcept {
    sdk::interfaces::RunInterfaces();
    handling::hooks::RunHooks();

    handling::utils::RunRender();

    handling::utils::Netvar = std::make_unique <handling::utils::netvar_tree> ();

    return TRUE;
}

DWORD APIENTRY ShutdownDllHandling(HINSTANCE module_handle) noexcept {
    sdk::interfaces::ShutdownInterfaces();
    handling::hooks::ShutdownHooks();

    handling::utils::ShutdownRender();

    handling::utils::Netvar = nullptr;

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE HModule, DWORD ULReasonForCall, LPVOID LPReserved) noexcept {
    switch (ULReasonForCall) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(HModule);
        CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)RunDllHandling, nullptr, NULL, nullptr);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        (LPTHREAD_START_ROUTINE)ShutdownDllHandling;
        break;
    }

    return TRUE;
}