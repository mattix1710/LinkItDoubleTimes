# CMakeList.txt: projekt CMake dla elementu LinkItDoubleTimes, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LinkItDoubleTimes")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (LinkItDoubleTimes "LinkItDoubleTimes.cpp" "LinkItDoubleTimes.h" "DoubleLinkedList.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LinkItDoubleTimes PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
