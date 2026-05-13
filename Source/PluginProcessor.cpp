#include "PluginProcessor.h"
#include "PluginEditor.h"

LYNEVIPluginProcessor::LYNEVIPluginProcessor()
    : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true)
                                       .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{}

void LYNEVIPluginProcessor::prepareToPlay(double, int) {}
void LYNEVIPluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    buffer.clear(); // TODO: NAM integration coming next
}

juce::AudioProcessorEditor* LYNEVIPluginProcessor::createEditor() {
    return new LYNEVIPluginEditor(*this);
}