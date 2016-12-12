/*
 * Logable.cpp
 *
 *  Created on: 9 nov. 2016
 *      Author: diego
 */

#include <Loggable.h>
#include <spdlog/spdlog.h>

namespace cpplogging {

namespace spd = spdlog;

Loggable::Loggable(std::string logname)
{
	Level = LogLevel::debug;
	SetLogName(logname);
}

Loggable::~Loggable() {
	spd::drop(LogName);
}

void Loggable::LogToConsole(bool _logtoconsole)
{

}

spdlog::level::level_enum Loggable::GetSpdLevel(LogLevel _level)
{
    switch(_level)
    {
    case critical:
        return spd::level::critical;
        break;
    case debug:
        return spd::level::debug;
        break;
    case err:
        return spd::level::err;
        break;
    case info:
        return spd::level::info;
        break;
    case off:
        return spd::level::off;
        break;
    case trace:
        return spd::level::trace;
        break;
    case warn:
        return spd::level::warn;
        break;
    }
    return spd::level::info;
}

void Loggable::FlushLogOn(LogLevel level)
{
    Log->flush_on(GetSpdLevel(level));
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
	Level = _level;
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





} /* namespace cpplogging */
