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

namespace dccomms {

namespace spd = spdlog;

class Loggable {
public:
	enum LogLevel {critical, debug, err, info, off, trace, warn };

	Loggable(std::string logname = "console");
	virtual ~Loggable();

	void SetLogName(std::string name);
	void LogToConsole(bool);
	void SetLogLevel(LogLevel);

	std::string LogName;
	LogLevel Level;
	std::shared_ptr<spd::logger> Log;

};

} /* namespace dccomms */

#endif /* INCLUDES_LOGGABLE_H_ */
