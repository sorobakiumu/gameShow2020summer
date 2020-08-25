#include "File.h"
#include <DxLib.h>

File::File(int handle, Type type, const char* tag):handle_(handle),type_(type),tag_(tag){
	if (type == Type::data) {
		auto bgnIdx = FileRead_tell(handle);
		FileRead_seek(handle, 0, SEEK_END); 
		auto endIdx = FileRead_tell(handle); 
		auto fsize = endIdx - bgnIdx; 
		FileRead_seek(handle, 0, SEEK_SET);
		data_.resize(fsize);
		FileRead_read(data_.data(), static_cast<const unsigned int>(fsize), handle);
		FileRead_close(handle);
	}
}

File::~File()
{
	switch (type_)
	{
	case Type::image:
		DeleteGraph(handle_);
		break;
	case Type::sound:
		DeleteSoundMem(handle_);
		break;
	case Type::data:
		//データ本体の削除
	default:
		break;
	}
}

int File::Handle() const
{
	return handle_;
}

std::vector<uint8_t> File::Data()
{
	return data_;
}

bool File::IsLoaded() const
{
	return true;
}

const std::string File::GetTag()
{
	return tag_;
}

void File::FCopyRead(void* data, size_t size)
{
	uint8_t* d = static_cast<uint8_t*>(data);
	auto itBgn = data_.begin();
	copy_n(next(itBgn, cursor_), size, d); 
	cursor_ += size;
}