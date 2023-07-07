# enable C++ module support
cmake_minimum_required( VERSION 3.25 )
# test if CMake version is ≥ 3.26
if ( ${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.26 )
  # CMake 3.26; need to handle future versions here
  set( CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 2182bf5c-ef0d-489a-91da-49dbc3090d2a )
else()
  # CMake 3.25
  set( CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API 3c375311-a3c9-4396-a187-3227ef642046 )
endif()
set( CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1 )

project(vulkan-cpp23)

set(CMAKE_CXX_STANDARD 23)

# find Vulkan SDK
find_package( Vulkan REQUIRED )
message(STATUS "find vulkan :${Vulkan_VERSION} ${CMAKE_CURRENT_SOURCE_DIR}")

# set up Vulkan C++ module
add_library(VulkanCppModule)
target_sources(VulkanCppModule PRIVATE
  FILE_SET CXX_MODULES
  FILES  Vulkan-Hpp/vulkan/vulkan.cppm
)
target_link_libraries(VulkanCppModule  ${Vulkan_LIBRARIES})
target_include_directories(VulkanCppModule PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Hpp" "${CMAKE_CURRENT_SOURCE_DIR}/Vulkan-Hpp/Vulkan-Headers/include" )  

# link Vulkan C++ module into your project
add_executable(${PROJECT_NAME}-A A.cpp)
target_link_libraries(${PROJECT_NAME}-A VulkanCppModule)