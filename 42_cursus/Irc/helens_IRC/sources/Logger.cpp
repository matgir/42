/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:28:32 by Helene            #+#    #+#             */
/*   Updated: 2024/09/25 16:18:53 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Logger.hpp"

Logger::Logger(std::string const& logFileName)
{
    _logFile.open(logFileName.c_str(), std::ofstream::out | std::ofstream::app); // if open fails, the failbit state flag if set for the stream (how do we check the stream's state flags ?)
    if (!_logFile.is_open())
        std::cerr << "[Logger Error] : failed to open the given log file" << std::endl;
}

 Logger::~Logger()
 {
    if (_logFile.is_open())
        _logFile.close();
 }

std::string Logger::getLevel(e_logLevel const& level) const
{
    switch (level)
    {
        case INFO:
            return "INFO";
        case DEBUG:
            return "DEBUG";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        case CRITICAL:
            return "CRITICAL";
        default:
            return "UNKNOWN LOG LEVEL";
    }
}

std::string    Logger::getLevelColor(e_logLevel const& level) const 
{
    switch (level)
    {
        case INFO:
            return GRN;
        case DEBUG:
            return YEL;
        case WARNING:
            return MAG;
        case ERROR:
            return RED;
        case CRITICAL:
            return BLU; 
        default:
            return "UNKNOWN LOG LEVEL";
    }
}

void    Logger::log(e_logLevel const& level, std::string const& msg)
{
    // create log entry
    std::ostringstream logEntry;
    logEntry << getLevelColor(level) << "[" << getLevel(level) << "] : " << msg << WHT << std::endl;
        
    // output to Logger
        std::cout << logEntry.str();
        
    // output to log file, if a log file was given at construction of Logger
    if (_logFile.is_open())
    {
        _logFile << logEntry.str();
        _logFile.flush(); // same as _logFile << std::endl ? minus the '\n' obv
    }
}
    