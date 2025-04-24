# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ZabaNaUlicy_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ZabaNaUlicy_autogen.dir\\ParseCache.txt"
  "ZabaNaUlicy_autogen"
  )
endif()
