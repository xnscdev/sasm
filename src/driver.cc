/*************************************************************************
 * driver.cc -- This file is part of sasm.                               *
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

#include <cstring>
#include "error.hh"
#include "gen-obj.hh"

extern FILE *yyin;

ObjectFileFormat format;
std::string filename;
Object *result;

int yyparse (void);

int
main (int argc, char **argv)
{
  init_colors ();
  format = ObjectFileFormat::BINARY32;

  if (argc < 2)
    exit (1);
  yyin = fopen (argv[1], "r");
  if (yyin == nullptr)
    fatal_error (std::string (argv[1]) + ": failed to open: " +
		 strerror (errno));
  return yyparse ();
}
