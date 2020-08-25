#pragma once
#include<unordered_map>
#include<string>
#include <memory>

class File;
class FileManager
{
	friend File;
private:
	std::unordered_map <std::wstring, std::shared_ptr<File>> resourceTable_;
	FileManager();
	FileManager(const FileManager&) = delete;
	void operator=(const FileManager&) = delete;
public:
	~FileManager() = default;
	static FileManager& Instance();
	std::shared_ptr<File> Load(const wchar_t* filepath, const char* tag);

	void DeleteAllResources();
	void DeleteResourcesByTag(const char* tag);
};

