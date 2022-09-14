#pragma once
#include <memory>
#include <string>


#if defined(PREMAN_DEBUG)
	#define LOG_TEXT(...)	    Logger::GetLogger().Log(Verbosity::Normal, __VA_ARGS__)
	#define LOG_ERROR(...)		Logger::GetLogger().Log(Verbosity::Error, __VA_ARGS__)
	#define LOG_WARNING(...)	Logger::GetLogger().Log(Verbosity::Warning, __VA_ARGS__)
	#define LOG_FATAL(...)		Logger::GetLogger().Log(Verbosity::Fatal, __VA_ARGS__)
#endif

enum class Verbosity : int8_t
{
	Unknown = -1,
	Normal = 0,
	Error = 1,
	Warning = 2,
	Fatal = 3
};

class Logger
{
	std::string m_format;
public:
	void SetFormat(const std::string& format);
	static Logger& GetLogger();
	void Log(Verbosity verbosity, const std::string& message) const;
};