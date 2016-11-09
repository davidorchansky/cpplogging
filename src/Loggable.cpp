/*
 * Logable.cpp
 *
 *  Created on: 9 nov. 2016
 *      Author: diego
 */

#include <Loggable.h>
#include <spdlog/spdlog.h>

namespace dccomms {

namespace spd = spdlog;

Loggable::Loggable(std::string logname)
{
	Level = LogLevel::debug;
	SetLogName(logname);
}

Loggable::~Loggable() {
	spd::drop(LogName);
}


void Loggable::SetLogName(std::string newname)
{
	if(newname != LogName)
	{
		if(Log)
		{
			spd::drop(LogName);
		}
		LogName = newname;

		Log = spd::get(LogName);
		if(!Log)
		{
			Log = spd::stdout_color_mt(LogName);
		}
		SetLogLevel(Level);
	}
}

void Loggable::SetLogLevel(LogLevel _level)
{
	if(Log)
	{
		switch(_level)
		{
		case critical:
			Log->set_level(spd::level::critical);
			break;
		case debug:
			Log->set_level(spd::level::debug);
			break;
		case err:
			Log->set_level(spd::level::err);
			break;
		case info:
			Log->set_level(spd::level::info);
			break;
		case off:
			Log->set_level(spd::level::off);
			break;
		case trace:
			Log->set_level(spd::level::trace);
			break;
		case warn:
			Log->set_level(spd::level::warn);
			break;
		}
	}
}





} /* namespace dccomms */
