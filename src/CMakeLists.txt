cmake_minimum_required(VERSION 3.10)

set(EXE_NAME calculator_executable)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.h")
file(GLOB_RECURSE UI_FILES CONFIGURE_DEPENDS "*.ui")
file(GLOB_RECURSE RESOURCES CONFIGURE_DEPENDS "*.qrc")


add_executable(${EXE_NAME} 
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
    )



target_link_libraries(${EXE_NAME} PUBLIC  project_options)

target_link_libraries(${EXE_NAME}
    PRIVATE
        Qt::Core
        Qt::Widgets
)


