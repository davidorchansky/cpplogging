/*
 * Logable.h
 *
 *  Created on: 9 nov. 2016
 *      Author: diego
 */

#ifndef INCLUDES_LOGGABLE_H_
#define INCLUDES_LOGGABLE_H_

#include <string>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>
#include <spdlog/sinks/ansicolor_sink.h>
#include <iostream>
#include <memory>

namespace cpplogging {

namespace spd = spdlog;

class Loggable {
public:
	enum LogLevel {critical, debug, err, info, off, trace, warn };

        Loggable(std::string logname = "log");
	virtual ~Loggable();

        virtual void SetLogName(std::string name);
        virtual void LogToFile(const std::string & filename );
	virtual void LogToConsole(bool);
	virtual void SetLogLevel(Loggable::LogLevel);
	virtual std::string GetLogName(){return LogName;};
        virtual void FlushLogOn(LogLevel);
        virtual void FlushLog();
protected:
        std::shared_ptr<spd::sinks::dist_sink_mt> dist_sink;
        //std::shared_ptr<spd::sinks::stdout_sink_mt> console_sink;
        std::shared_ptr<spdlog::sinks::ansicolor_sink> console_sink;

        spdlog::level::level_enum GetSpdLevel(LogLevel);
	std::string LogName;
	LogLevel Level;
	std::shared_ptr<spd::logger> Log;
        bool logToConsole;

};

} /* namespace cpplogging */

#endif /* INCLUDES_LOGGABLE_H_ */
