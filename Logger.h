#define _CRT_SECURE_NO_WARNINGS
#ifndef LOGGER_H_
#define LOGGER_H_
#include <array>
#include <string>
#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>

namespace Log {
	namespace LOG_TAGS {
		enum {
			INFO,
			DEBUG,
			WARNING,
			FATAL,
			FUNCTION_MESSAGE,
			FUNCTION_ERROR
		};
	}
	
	namespace LOG_WRITE_MODE {
		enum {
			CONSOLE,
			FILE
		};
	}
	
	class Logger final
	{
		Logger() = default;
		~Logger() = default;
		static std::array<std::string, 6> TAGS;
		static void logToStderr(int tag, std::string classNameANDFunctionName, std::string message);
		static void logToFile(int tag, std::string classNameANDFunctionName, std::string message);
		static std::string formatClassAndFunctionName(std::string classNameANDFunctionName);
	public:
		static void __writeLog(int writeMode, int tag, std::string classNameANDFunctionName, std::string message);
	};
}

#define LogHere(writeMode, tag, message) Log::Logger::__writeLog(writeMode, tag, __FUNCSIG__, message)
#endif // LOGGER_H_


