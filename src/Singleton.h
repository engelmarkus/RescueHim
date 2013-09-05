#pragma once

/**
  * @brief A simple singleton implementation.
  * @tparam T The class to create a singleton of.
  * @remarks Do not use this singleton when your code relies on the encapsulated object on destruction.
  * The instance may be destructed at any time during program exit.
  */
template<class T>
struct Singleton {
    /// @returns A reference to the instance.
	static T& instance() {
		static T inst;
		return inst;
	}
};

