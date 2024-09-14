file(GLOB_RECURSE
	LANGULUS_MOD_UMS_TEST_SOURCES 
	LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
	*.cpp
)

add_executable(LangulusModUMSTest ${LANGULUS_MOD_UMS_TEST_SOURCES})

target_link_libraries(LangulusModUMSTest
	PRIVATE		Langulus
				Catch2
)

add_dependencies(LangulusModUMSTest
	LangulusModUMS
)

add_test(
	NAME		LangulusModUMSTest
	COMMAND		LangulusModUMSTest
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)