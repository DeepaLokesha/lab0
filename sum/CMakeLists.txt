cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(sum)

target_sources(app PRIVATE src/main.c)
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(CONFIG_SUM_PRINT)
	target_sources(app PRIVATE sum_printk/sum_printk.c)
elseif(CONFIG_SUM_LOG)
	target_sources(app PRIVATE sum_log/sum_log.c)
endif()
