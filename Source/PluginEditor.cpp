#include "PluginEditor.h"

LYNEVIPluginEditor::LYNEVIPluginEditor(LYNEVIPluginProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(800, 500);

    auto addKnob = [&](juce::Slider& knob, int x, int y, int size = 55) {
        knob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        knob.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        addAndMakeVisible(knob);
        knob.setBounds(x, y, size, size);
    };

    addKnob(driveKnob, 120, 140);
    addKnob(bassKnob, 240, 80);
    addKnob(middleKnob, 320, 70);
    addKnob(trebleKnob, 400, 80);
    addKnob(presenceKnob, 520, 140);
    addKnob(chanVolKnob, 680, 220);
    addKnob(reverbKnob, 680, 340);
    addKnob(outputKnob, 120, 340);
    addKnob(ampModelsKnob, 280, 420, 70);
    addKnob(effectsKnob, 520, 420, 70);
}

void LYNEVIPluginEditor::paint(juce::Graphics& g)
{
    if (backgroundImage.isValid())
        g.drawImage(backgroundImage, getLocalBounds().toFloat());
    else
        g.fillAll(juce::Colour(0xFFCC0000)); // Red bean fallback

    g.setColour(juce::Colours::white);
    g.setFont(16.0f);

    g.drawText("DRIVE", 115, 205, 70, 20, juce::Justification::centred);
    g.drawText("BASS", 235, 135, 70, 20, juce::Justification::centred);
    g.drawText("MIDDLE", 315, 125, 70, 20, juce::Justification::centred);
    g.drawText("TREBLE", 395, 135, 70, 20, juce::Justification::centred);
    g.drawText("PRESENCE", 515, 205, 70, 20, juce::Justification::centred);
    g.drawText("CHAN VOL", 665, 280, 80, 20, juce::Justification::centred);
    g.drawText("REVERB", 665, 400, 80, 20, juce::Justification::centred);
    g.drawText("OUTPUT", 115, 400, 70, 20, juce::Justification::centred);
    g.drawText("AMP MODELS", 260, 490, 110, 20, juce::Justification::centred);
    g.drawText("EFFECTS", 510, 490, 100, 20, juce::Justification::centred);
}

void LYNEVIPluginEditor::resized() {}