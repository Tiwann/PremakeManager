#pragma once

class Logger 
{
	static Logger s_logger;
public:
	static Logger& GetLogger() { return s_logger; }
	
};