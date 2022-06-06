cmake_minimum_required(VERSION 3.8)
project(ros2_sanitize)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Link this 'library' to set the compile-time options requested
add_library(project_options INTERFACE)

# sanitizer options
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(rclcpp_tests test/rclcpp_tests.cpp)
  target_link_libraries(rclcpp_tests project_options rclcpp::rclcpp)
endif()

ament_package()
