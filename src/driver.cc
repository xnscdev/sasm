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
#include <getopt.h>
#include <iostream>
#include <set>
#include "error.hh"
#include "gen-obj.hh"
#include "util.hh"

static const struct option long_options[] = {
  {"format", required_argument, nullptr, 'f'},
  {"output", required_argument, nullptr, 'o'},
  {"help", no_argument, nullptr, 'h'},
  {"version", no_argument, nullptr, 'v'}
};

static const struct
{
  const char *flag;
  const char *desc;
} help_options[] = {
  {"-f FMT, --format=FMT", "Change the output object format"},
  {"-o FILE, --output=FILE", "Write output to FILE"},
  {"-h, --help", "Show this help text and exit"},
  {"-v, --version", "Show the version of this program and exit"},
  {nullptr, nullptr}
};

static std::set <std::string> binary_names {"raw", "bin", "binary"};
static std::set <std::string> elf_names {"elf", "elf32"};
static std::set <std::string> coff_names {"coff", "coff32", "win", "win32"};

extern FILE *yyin;

ObjectFileFormat format;
std::string filename;
Object *result;
std::string output_filename;
FILE *output;

int yyparse (void);

static void
usage (void)
{
  printf ("Usage: sasm [-f FMT] [-o FILE] INPUT\n"
	  "       sasm [-h | -v]\nOptions:\n");
  for (size_t i = 0; help_options[i].flag != nullptr; i++)
    printf ("  %-34s %s\n", help_options[i].flag, help_options[i].desc);
}

static void
version (void)
{
  printf ("sasm assembler, version " PACKAGE_VERSION "\n");
}

static ObjectFileFormat
parse_format (std::string name)
{
  if (binary_names.find (name) != binary_names.end ())
    return ObjectFileFormat::BINARY32;
  if (elf_names.find (name) != elf_names.end ())
    return ObjectFileFormat::ELF32;
  if (coff_names.find (name) != coff_names.end ())
    return ObjectFileFormat::COFF32;
  error ("unknown or unsupported object format");
  exit (1);
}

static void
parse_options (int argc, char *const *argv)
{
  int opt;
  while ((opt = getopt_long (argc, argv, ":fohv", long_options, nullptr)) != -1)
    {
      switch (opt)
        {
	case 'f':
	  format = parse_format (optarg);
	  break;
	case 'o':
	  output_filename = optarg;
	  break;
	case 'h':
	  usage ();
	  exit (0);
	case 'v':
	  version ();
	  exit (0);
	default:
	  error ("invalid options specified, exiting");
	  exit (1);
	}
    }
}

int
main (int argc, char **argv)
{
  init_colors ();
  parse_options (argc, argv);

  if (optind >= argc)
    fatal_error ("no input files");
  else if (optind < argc - 1)
    fatal_error ("too many input files");
  if (format == ObjectFileFormat::NONE)
    fatal_error ("no output format specified");
  yyin = fopen (argv[optind], "r");
  if (yyin == nullptr)
    fatal_error (std::string (argv[optind]) + ": failed to open: " +
		 strerror (errno));
  if (output_filename.empty ())
    output_filename = "a.out";

  if (yyparse () != 0)
    exit (1);

  result->switch_section (".text");
  for (AsmLine *line : result->lines)
    {
      if (ISINSTANCE (AsmIdentifier *, line))
	{
	  AsmIdentifier *ident = CAST (AsmIdentifier *, line);
	  AsmLabel *label =
	    new AsmLabel (ident->name, result->section, AsmLabelBinding::LOCAL,
			  AsmLabelType::NONE, 0);
	  result->add_label (label);
	}
      else if (ISINSTANCE (AsmInst *, line))
	{
	  AsmInst *inst = CAST (AsmInst *, line);
	  if (!result->assemble_inst (inst))
	    error ("invalid instruction and/or operands");
	}
    }
  if (error_occurred)
    exit (1);

  output = fopen (output_filename.c_str (), "wb");
  if (output == nullptr)
    fatal_error (output_filename + ": failed to open: " +
		 strerror (errno));

  bool ret = result->write (output);
  fclose (output);
  return ret ? 0 : 1;
}
