#include <iostream>
#include "windows.h"

#include <vector>
#include <string>

DWORD base = (DWORD)GetModuleHandleA(0);

// copy paste god
bool write_bytes(
    const std::uintptr_t address,
    std::vector<uint8_t> const& bytes)
{
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(address),
        bytes.data(),
        bytes.size(),
        nullptr);
}

DWORD WINAPI main(void* hModule)
{
    // AntiCheat Level Completion Bypass
    write_bytes(base + 0x1FD557, { 0xEB, 0x0C, });
    write_bytes(base + 0x1FD742, { 0xC7, 0x87, 0xE0, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x87, 0xE4, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    write_bytes(base + 0x1FD756, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    write_bytes(base + 0x1FD79A, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    write_bytes(base + 0x1FD7AF, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });



    return true;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, main, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
