# cmake_minimum_required(VERSION 3.22)
project(LYNE_VI VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(JUCE)

juce_add_binary_data(LYNE_VI_Data
    NAMESPACE BinaryData
    SOURCES Assets/bean_red.png
)

juce_add_plugin(LYNE_VI
    PRODUCT_NAME "LYNE VI"
    COMPANY_NAME "NeuralBean"
    BUNDLE_ID "com.neuralbean.lynevi"
    PLUGIN_MANUFACTURER_CODE "NBBE"
    PLUGIN_CODE "LYVI"
    FORMATS VST3 Standalone
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
)

juce_generate_juce_header(LYNE_VI)

target_sources(LYNE_VI PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/LcdDisplay.cpp
)

target_link_libraries(LYNE_VI PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    LYNE_VI_Data
)

target_compile_definitions(LYNE_VI PRIVATE
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)
