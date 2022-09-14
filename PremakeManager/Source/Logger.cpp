#include "Logger.h"
#include <iostream>
#include <ctime>
#include <chrono>

void Logger::SetFormat(const std::string& format)
{
	GetLogger().m_format = format;
}

Logger& Logger::GetLogger()
{
	static std::unique_ptr<Logger> logger = std::make_unique<Logger>(Logger());
	return *logger;
}

void Logger::Log(Verbosity verbosity, const std::string& message) const
{
	std::cout << message;
}
