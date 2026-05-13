#include "PluginEditor.h"

LYNEVIPluginEditor::LYNEVIPluginEditor(LYNEVIPluginProcessor& p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    setSize(800, 500);

    lcdDisplay = std::make_unique<LcdDisplay>();
    addAndMakeVisible(*lcdDisplay);
    lcdDisplay->setBounds(280, 160, 320, 140);

    auto setupKnob = [&](juce::Slider& knob, int x, int y) {
        knob.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        knob.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        addAndMakeVisible(knob);
        knob.setBounds(x, y, 58, 58);
    };

    setupKnob(driveKnob, 118, 138);
    setupKnob(bassKnob, 235, 78);
    setupKnob(middleKnob, 315, 68);
    setupKnob(trebleKnob, 395, 78);
    setupKnob(presenceKnob, 518, 138);
    setupKnob(chanVolKnob, 675, 215);
    setupKnob(reverbKnob, 675, 335);
    setupKnob(outputKnob, 118, 335);
    setupKnob(ampModelsKnob, 275, 415);
    setupKnob(effectsKnob, 515, 415);
}

void LYNEVIPluginEditor::paint(juce::Graphics& g)
{
    // Background
    if (backgroundImage.isNull())
        backgroundImage = juce::ImageCache::getFromMemory(BinaryData::bean_red_png, BinaryData::bean_red_pngSize);

    if (backgroundImage.isValid())
        g.drawImage(backgroundImage, getLocalBounds().toFloat());
    else
        g.fillAll(juce::Colour(0xFFCC0000));   // fallback red

    // Labels
    g.setColour(juce::Colours::white);
    g.setFont(15.0f);
    g.drawText("DRIVE",     115, 205, 70, 20, juce::Justification::centred);
    g.drawText("BASS",      235, 135, 70, 20, juce::Justification::centred);
    g.drawText("MIDDLE",    315, 125, 70, 20, juce::Justification::centred);
    g.drawText("TREBLE",    395, 135, 70, 20, juce::Justification::centred);
    g.drawText("PRESENCE",  515, 205, 80, 20, juce::Justification::centred);
    g.drawText("CHAN VOL",  665, 275, 80, 20, juce::Justification::centred);
    g.drawText("REVERB",    665, 395, 80, 20, juce::Justification::centred);
    g.drawText("OUTPUT",    115, 395, 70, 20, juce::Justification::centred);
    g.drawText("AMP MODELS",270, 490, 110, 20, juce::Justification::centred);
    g.drawText("EFFECTS",   510, 490, 100, 20, juce::Justification::centred);
}

void LYNEVIPluginEditor::resized()
{
    lcdDisplay->setBounds(280, 160, 320, 140);
}