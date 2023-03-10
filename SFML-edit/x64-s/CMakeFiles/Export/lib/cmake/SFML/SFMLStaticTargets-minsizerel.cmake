#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sfml-system" for configuration "MinSizeRel"
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sfml-system-s.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS sfml-system )
list(APPEND _IMPORT_CHECK_FILES_FOR_sfml-system "${_IMPORT_PREFIX}/lib/sfml-system-s.lib" )

# Import target "sfml-main" for configuration "MinSizeRel"
set_property(TARGET sfml-main APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(sfml-main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sfml-main.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS sfml-main )
list(APPEND _IMPORT_CHECK_FILES_FOR_sfml-main "${_IMPORT_PREFIX}/lib/sfml-main.lib" )

# Import target "sfml-window" for configuration "MinSizeRel"
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sfml-window-s.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS sfml-window )
list(APPEND _IMPORT_CHECK_FILES_FOR_sfml-window "${_IMPORT_PREFIX}/lib/sfml-window-s.lib" )

# Import target "sfml-network" for configuration "MinSizeRel"
set_property(TARGET sfml-network APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(sfml-network PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sfml-network-s.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS sfml-network )
list(APPEND _IMPORT_CHECK_FILES_FOR_sfml-network "${_IMPORT_PREFIX}/lib/sfml-network-s.lib" )

# Import target "sfml-graphics" for configuration "MinSizeRel"
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sfml-graphics-s.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS sfml-graphics )
list(APPEND _IMPORT_CHECK_FILES_FOR_sfml-graphics "${_IMPORT_PREFIX}/lib/sfml-graphics-s.lib" )

# Import target "sfml-audio" for configuration "MinSizeRel"
set_property(TARGET sfml-audio APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(sfml-audio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/sfml-audio-s.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS sfml-audio )
list(APPEND _IMPORT_CHECK_FILES_FOR_sfml-audio "${_IMPORT_PREFIX}/lib/sfml-audio-s.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
