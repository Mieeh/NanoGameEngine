#pragma once

#include<string>

struct GLFWwindow;

namespace nano {
	namespace math {
		class Vector2;
	}
	class CoreConfig;
}

namespace nano { namespace graphics { 

	class WindowOwner {
	public:
		virtual void WindowResized(int a_width, int a_height) { }
	};

	class Window {
	public:
		// Constructor
		Window(const math::Vector2& a_windowSize, const std::string& a_windowCaption = "Nano Game Engine");

		// Destructor
		~Window();

		// Public methods
		void Close();
		void Clear();
		void Display();

		// Public methods (getters)
		const bool IsOpen();
		const GLFWwindow* GetGLFWwindow();

		// GLFW callbacks
		static friend void window_size_callback(GLFWwindow* window, int width, int height);

		// @ TEMPORARY HOTFIX
		WindowOwner *owner;

	private:
		CoreConfig *config;
		GLFWwindow *m_glfwWindow;
	};

} } 