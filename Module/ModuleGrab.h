#pragma once
#include <Windows.h>

HMODULE WINAPI GetModuleA(_In_opt_ LPCSTR  lpModuleName);

HMODULE WINAPI GetModuleW(_In_opt_ LPCWSTR lpModuleName);

wchar_t* GetFileNameFromPath(wchar_t* Path);

wchar_t* RemoveFileExtension(wchar_t* FullFileName, wchar_t* OutputBuffer, DWORD OutputBufferSize);

