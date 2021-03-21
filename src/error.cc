/*************************************************************************
 * error.cc -- This file is part of sasm.                                *
 * Copyright (C) 2021                                                    *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program. If not, see <https://www.gnu.org/licenses/>. *
 *************************************************************************/

#include <iostream>
#include <unistd.h>
#include "error.hh"

extern int yylineno;

bool colors;
bool error_occurred;

void
init_colors (void)
{
  colors = isatty (STDERR_FILENO);
}

void
warning (std::string str)
{
  if (colors)
    std::cerr << "\033[33mwarning: \033[0m";
  else
    std::cerr << "warning: ";
  std::cerr << str << std::endl;
}

void
error (std::string str)
{
  if (colors)
    std::cerr << "\033[31merror: \033[0m";
  else
    std::cerr << "error: ";
  std::cerr << str << std::endl;
  error_occurred = true;
}

void
fatal_error (std::string str)
{
  if (colors)
    std::cerr << "\033[31;1mfatal error: \033[0m";
  else
    std::cerr << "fatal error: ";
  std::cerr << str << std::endl;
  exit (1);
}
