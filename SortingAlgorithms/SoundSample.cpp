#include "SoundSample.h"

SoundBuffer CreateBuffer()
{
	const unsigned int sampleRate = 44100;
	const float frequency = 300.0f;
	const float duration = 0.01f;
	const float amplitude = 32767.0f;

	const unsigned int numSamples = static_cast<unsigned int>(sampleRate * duration);

	sf::Int16* samples = new sf::Int16[numSamples];

	for (unsigned int i = 0; i < numSamples; ++i)
	{
		float time = static_cast<float>(i) / sampleRate;
		samples[i] = static_cast<sf::Int16>(amplitude * sin(2 * M_PI * frequency * time));
	}

	sf::SoundBuffer buffer;
	buffer.loadFromSamples(samples, numSamples, 1, sampleRate);

	delete[] samples;

	return buffer;
}