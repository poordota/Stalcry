# Install script for directory: C:/Users/Asus/source/repos/_Stalcry_/SFML-2.5.1-src/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/SFML")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/ftp/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/sockets/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/voip/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/sound/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/sound_capture/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/window/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/joystick/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/opengl/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/shader/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/island/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/win32/cmake_install.cmake")
  include("C:/Users/Asus/source/repos/_Stalcry_/SFML-edit/x64-s/examples/pong/cmake_install.cmake")

endif()

