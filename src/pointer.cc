/*************************************************************************
 * pointer.cc -- This file is part of sasm.                              *
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
#include "error.hh"
#include "inst.hh"
#include "util.hh"

uint32_t
AsmImmediate::get_addr (void)
{
  return value;
}

uint32_t
AsmIdentifier::get_addr (void)
{
  for (std::map <std::string, uint32_t>::iterator it = label_addrs.begin ();
       it != label_addrs.end (); it++)
    {
      if (name == it->first)
	return it->second;
    }
  error ("undefined identifier: " + name);
  return 0;
}
