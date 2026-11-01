file(GLOB SOURCES "src/*.cpp" "src/drivers/stm32g4/*.cpp")
add_executable(zactuator_desktop ${SOURCES})

target_include_directories(zactuator_desktop PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MCU_TARGET)
    message(STATUS "Configuring Embedded Hardware Target for Actuator...")

    add_executable(zactuator_firmware ${SOURCES})

    set_target_properties(zactuator_firmware PROPERTIES SUFFIX ".elf")

    target_include_directories(zactuator_firmware PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

    target_link_libraries(zactuator_firmware PRIVATE
    HAL_LIB
    DSP_LIB
    STM32G4_PLATFORM
    STM32G4_BUILD_OPTIONS
    )

    target_link_options(zactuator_firmware PRIVATE
    -T${CMAKE_SOURCE_DIR}/platform/stm32g4/STM32G474RETx_FLASH.ld
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,-Map=zactuator_firmware.map
    -Wl,--gc-sections
)

    find_program(OPENOCD_BIN openocd)

    if(OPENOCD_BIN)
        add_custom_target(flash
            COMMAND ${OPENOCD_BIN} -f interface/stlink.cfg -f target/stm32g4x.cfg -c "program ${CMAKE_CURRENT_BINARY_DIR}/zactuator_firmware.elf verify reset exit"
            DEPENDS zactuator_firmware
            COMMENT "Flashing firmware to STM32 target using OpenOCD."
        )
    else()
        message(WARNING "OpenOCD not found. Flashing target will not be available.")
    endif()

endif()