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

namespace cpplogging {

namespace spd = spdlog;

class Loggable {
public:
	enum LogLevel {critical, debug, err, info, off, trace, warn };

	Loggable(std::string logname = "console");
	virtual ~Loggable();

	virtual void SetLogName(std::string name);
	virtual void LogToConsole(bool);
	virtual void SetLogLevel(Loggable::LogLevel);

	std::string LogName;
	LogLevel Level;
	std::shared_ptr<spd::logger> Log;

};

} /* namespace cpplogging */

#endif /* INCLUDES_LOGGABLE_H_ */
