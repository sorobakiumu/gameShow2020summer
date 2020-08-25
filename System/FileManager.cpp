#include "FileManager.h"
#include<DxLib.h>
#include<cassert>
#include <functional>
#include<algorithm>
#include"File.h"


namespace {

	///Šg’£Žq‚ð•Ô‚·
	std::wstring GetExtension(const std::wstring& filepath) {
		auto idx = filepath.rfind(L".");
		assert(idx != std::wstring::npos);
		++idx;
		return filepath.substr(idx, filepath.length() - idx);
	}

	struct HandleAndType{
			int hadele;
			File::Type type;
	};
	std::unordered_map<std::wstring, std::function<HandleAndType(const wchar_t*)>> loader_;
}

FileManager::FileManager() {
	loader_[L"bmp"] = loader_[L"png"] = loader_[L"jpg"] = [](const wchar_t* path)->HandleAndType {
		return { LoadGraph(path),File::Type::image };
	};
	loader_[L"mp3"] = loader_[L"wav"] = [](const wchar_t* path) ->HandleAndType {
		return { LoadSoundMem(path),File::Type::sound };
	};
}

FileManager& FileManager::Instance()
{
	static FileManager instance;
	return instance;
}

std::shared_ptr<File> FileManager::Load(const wchar_t* filepath,const char* tag)
{
	assert(DxLib_IsInit());
	if (resourceTable_.count(filepath) == 0) {
		auto ext = GetExtension(filepath);
		auto file = loader_[ext](filepath);
		resourceTable_[filepath].reset(new File(file.hadele,file.type,tag));
	}
	return resourceTable_[filepath];
}

void FileManager::DeleteAllResources()
{
	resourceTable_.clear();
}

void FileManager::DeleteResourcesByTag(const char* tag)
{
	assert(tag != nullptr);
	auto it = resourceTable_.begin();
	while (it != resourceTable_.end()) {
		if (it->second->GetTag() == tag) {
			resourceTable_.erase(it);
		}
		else {
			++it;
		}
	}
}
