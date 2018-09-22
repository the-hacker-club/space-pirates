#include "GameWindow.h"

#include "ObjectMesh.h"

namespace WarpEngine
{

	GameWindow * GameWindow::_instance;
	vector<ObjectMesh*> GameWindow::gameObjects;

	// glfw: whenever the window size changed (by OS or user resize) this callback function executes
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);
	}

	GameWindow::GameWindow()
	{
		if (_instance == NULL) {
			init();
			_instance = this;
		}
	}


	GameWindow::~GameWindow()
	{
		// glfw: terminate, clearing all previously allocated GLFW resources.
		glfwTerminate();
	}

	GameWindow * GameWindow::getInstance()
	{
		return _instance;
	}

	void GameWindow::add(ObjectMesh * gameObject)
	{
		gameObjects.push_back(gameObject);
	}

	int GameWindow::init()
	{

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

		return 0;
	}

	int GameWindow::create(int width, int height)
	{
		window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			 return -1;
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		// glad: load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}    

		return 0;
	}

	void GameWindow::render()
	{
		processInput();

		// render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		// Render objects
		for (auto &gameObject : gameObjects) {
			gameObject->render();
		}

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
	}

	void GameWindow::setShouldClose(bool shouldClose)
	{
		glfwSetWindowShouldClose(window, shouldClose);
	}

	int GameWindow::shouldClose()
	{
		return glfwWindowShouldClose(window);
	}

	void GameWindow::processInput()
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}

}
