/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:28:45 by Helene            #+#    #+#             */
/*   Updated: 2024/09/25 16:18:58 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <stdio.h>
# include <iostream>
# include <sstream>
# include <fstream>

# define RED "\e[0;31m" // ERROR 
# define BLK "\e[0;30m"
# define GRN "\e[0;32m" // DEBUG 
# define YEL "\e[0;33m"  
# define BLU "\e[0;34m" // CRITICAL ?
# define MAG "\e[0;35m" // WARNING ?
# define CYN "\e[0;36m"
# define WHT "\e[0;37m" // INFO

# define RESET "\0e[0m" // a checker // "\033[0m" 

typedef enum
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
}   e_logLevel;

class Logger 
{
    public :
        Logger() {}
        Logger(std::string const& logFileName);
        ~Logger();
        void        log(e_logLevel const& level, std::string const& msg);
    
    private :
        std::string     getLevel(e_logLevel const& level) const;
        std::string     getLevelColor(e_logLevel const& level) const;
        std::ofstream   _logFile;
};