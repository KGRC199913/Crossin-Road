#include "Logger.h"

std::array<std::string, 6> Log::Logger::TAGS = {
	"[INFO]",
	"[DEBUG]",
	"[WARNING]",
	"[FATAL]",
	"[FUNCTION MESSAGE]",
	"[FUNCTION ERROR]"
};

void Log::Logger::logToStderr(int tag, std::string classNameANDFunctionName, std::string message)
{
	auto curTime = std::chrono::system_clock::now();
	auto curTime_t = std::chrono::system_clock::to_time_t(curTime);
	auto timeStruct = std::localtime(&curTime_t);
	std::cerr << TAGS[tag] << " at: " << timeStruct->tm_hour << ":" << timeStruct->tm_min << ":" << timeStruct->tm_sec
		<< " in " << classNameANDFunctionName << std::endl;
	std::cerr << "Message: " << message << std::endl;
}

void Log::Logger::logToFile(int tag, std::string classNameANDFunctionName, std::string message)
{
	auto curTime = std::chrono::system_clock::now();
	auto curTime_t = std::chrono::system_clock::to_time_t(curTime);
	auto timeStruct = std::localtime(&curTime_t);

	std::ofstream logFile(std::string(std::to_string(timeStruct->tm_mday) +
		"-" + std::to_string(timeStruct->tm_mon + 1) + "-" 
		+ std::to_string(timeStruct->tm_year + 1900) + ".txt" ), std::ios::app);
	
	if (!logFile)
		return;


	logFile << TAGS[tag] << " at: " << timeStruct->tm_hour << ":" << timeStruct->tm_min << ":" << timeStruct->tm_sec
		<< " in " << classNameANDFunctionName << std::endl;
	logFile << "Message: " << message << std::endl;

	logFile.close();
}

std::string Log::Logger::formatClassAndFunctionName(std::string classNameANDFunctionName)
{
	std::string formated;
	size_t begin = classNameANDFunctionName.rfind(" ") + 1;
	size_t end = classNameANDFunctionName.rfind("(") - begin;
	
	auto colonPos = classNameANDFunctionName.substr(begin, end).find("::");
	if (colonPos != std::string::npos) {
		formated = "Class: " 
			+ classNameANDFunctionName.substr(begin, end).replace(colonPos, colonPos + 1, " Method: ");
	}
	else
		formated = "Function: "
			+ classNameANDFunctionName.substr(begin, end) + " (no Class)";
	return formated;
}

void Log::Logger::__writeLog(int writeMode, int tag, std::string classNameANDFunctionName, std::string message)
{
	if (writeMode == Log::LOG_WRITE_MODE::CONSOLE)
		logToStderr(tag, formatClassAndFunctionName(classNameANDFunctionName), message);
	else
		logToFile(tag, formatClassAndFunctionName(classNameANDFunctionName), message);
}
