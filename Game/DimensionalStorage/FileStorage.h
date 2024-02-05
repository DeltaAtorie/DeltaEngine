#pragma once
class FileStorage : public IGameObject
{
public:
	FileStorage();
private:
	const wchar_t* SpriteFilePath[256];
	const wchar_t* ShaderFilePath[256];
	const wchar_t* SoundFilePath[256];
	const wchar_t* ModelFilePath[256];
	const wchar_t* FontFilePath[256];
	LPCWSTR FilePath;
	HANDLE HandleFile;
	DWORD FileSize;
};

