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
    // Level Completion
    write_bytes(base + 0x1FD557, { 0xEB, 0x0C, });
    write_bytes(base + 0x1FD742, { 0xC7, 0x87, 0xE0, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x87, 0xE4, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    write_bytes(base + 0x1FD756, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    write_bytes(base + 0x1FD79A, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    write_bytes(base + 0x1FD7AF, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });

    // Load Failed
    write_bytes(base + 0x18B2B4, { 0xB0 , 0x01 });

    //scroll
    write_bytes(base + 0x2E5CA, { 0xEB, });
    write_bytes(base + 0x2E5F8, { 0xEB, });

    //Object Bypass
    write_bytes(base + 0x73169, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x856A4, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x87B17, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x87BC7, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x87D95, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x880F4, { 0xFF, 0xFF, 0xFF, 0x7F });
    write_bytes(base + 0x160B06, { 0xFF, 0xFF, 0xFF, 0x7F });

    //Text Length
    write_bytes(base + 0x21ACB, { 0xEB, 0x04 });

    //Character Filter
    write_bytes(base + 0x21A99, { 0x90, 0x90 });

    //Default Song Bypass
    write_bytes(base + 0x174407, { 0x90, 0x90 });
    write_bytes(base + 0x174411, { 0x90, 0x90, 0x90 });
    write_bytes(base + 0x174456, { 0x90, 0x90 });
    write_bytes(base + 0x174460, { 0x90, 0x90, 0x90 });

    //Rotation Hack
    write_bytes(base + 0x85CBC, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0x90 });
    write_bytes(base + 0x8BDDD, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0x90 });
    write_bytes(base + 0x8BE16, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0x90 });
    write_bytes(base + 0xECA3D, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0x90 });
    write_bytes(base + 0xEE5A9, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0x90 });
    write_bytes(base + 0x20181E, { 0xB8, 0x01, 0x00, 0x00, 0x00, 0x90 });

    //Practice Pulse
    write_bytes(base + 0x205536, { 0x90, 0x90 });
    write_bytes(base + 0x20555D, { 0x90, 0x90 });
    write_bytes(base + 0x20553E, { 0xEB });

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
