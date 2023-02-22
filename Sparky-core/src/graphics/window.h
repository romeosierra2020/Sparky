#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace sparky {
	namespace graphics {
		class Window
		{
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;
		public:
			Window(const char* name, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;



			int getWidth() const;
			int getHeight() const;

		private:
			bool init();
		};
} }
