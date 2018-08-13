#
# Neon
# Copyright (C) 2018   REAL-TIME CONSULTING
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
# more details.
#
# You should have received a copy of the GNU Lesser General Public License along with
# this program. If not, see <http://www.gnu.org/licenses/>.
#

# Relative path to Neon common build directory.
WS = ..

# Common build script, contains common build rules and variables.
include $(WS)/build/common.mk

# Include depenencies, nlib exports common library variables, nport is needed
# to import additional build rules.
include $(WS)/lib/build/nlib.mk
include $(WS)/lib/build/nport.mk

# Project name, this will be used as output binary file name.
PROJECT_NAME := presenter

# List additional C header include paths.
CC_INCLUDES += apps/$(PROJECT_NAME)/app/include

# List additional C source files. Files which are not listed here will not be
# compiled.
CC_SOURCES += apps/$(PROJECT_NAME)/app/source/main.c
CC_SOURCES += apps/$(PROJECT_NAME)/app/source/support.c

# List additional archives. Use this when using an external static archive.
AR_LIBS +=

# List additional libraries. Use this when using an external static library.
LD_LIBS +=

# Define ALL rule.
all: $(PROJECT_ELF)

clean: clean-flash clean-size

distclean: 
	$(VERBOSE)rm -rf $(BUILD_DIR)

$(PROJECT_LIB): $(OBJECTS)

$(PROJECT_ELF): $(PROJECT_LIB)

$(PROJECT_SIZE): $(PROJECT_ELF)

$(PROJECT_FLASH): $(PROJECT_ELF)

# Include autogenerated dependency rules.
-include $(DEPENDS)
