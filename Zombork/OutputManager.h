#pragma once
class OutputManager
{
public:
	static OutputManager &instance()
	{
		static OutputManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	};

	void printOutput(string output);
};

