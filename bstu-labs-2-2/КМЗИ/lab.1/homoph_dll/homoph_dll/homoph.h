#pragma once
#include <string>

#ifdef HOMOPH_DLL_EXPORTS
#define HOMOPH_API __declspec(dllexport)
#else
#define HOMOPH_API __declspec(dllimport)
#endif

namespace homoph
{
	extern "C" HOMOPH_API int EncodeFileWithCSV(const std::string& file, const std::string& csv_file);
	extern "C" HOMOPH_API int EncodeFileWithCSV_n(const std::string& src, const std::string& dst, const std::string csv_file);
	extern "C" HOMOPH_API int DecodeFileWithCSV(std::string& file, const std::string& csv_file);
	extern "C" HOMOPH_API int DecodeFileWithCSV_n(const std::string& src, const std::string& dst, const std::string& csv_file);
}