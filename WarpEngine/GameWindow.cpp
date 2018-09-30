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
        this->width = width;
        this->height = height;

		window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			 return -1;
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        // Hide the mouse
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		// glad: load all OpenGL function pointers
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}    

        // Enable z-buffering
        glEnable(GL_DEPTH_TEST);

        // Create a default main camera
        mainCamera = make_unique<Camera>();
        mainCamera->translate(0.0f, 0.0f, 3.0f);

		return 0;
	}

	void GameWindow::render()
	{
		processInput();

		// render
        glClearColor(0.01f, 0.01f, 0.01f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render objects
		for (auto &gameObject : gameObjects) {
			gameObject->render();
		}

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
	}

	void _mouseHandler(GLFWwindow * window, double mouseX, double mouseY)
    {
        if (GameWindow::getInstance()->mouseHandler != NULL) {
            GameWindow::getInstance()->mouseHandler(mouseX, mouseY);
        }
    }

    void GameWindow::setMouseHandler(void (*mouseHandlerParam)(double mouseX, double mouseY))
    {
        mouseHandler = mouseHandlerParam;
        glfwSetCursorPosCallback(window, &_mouseHandler);
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

        if (glfwGetKey(this->window, GLFW_KEY_W) == GLFW_PRESS) {
            mainCamera->translate(mainCamera->getForwardVector() * mainCamera->speed);
        }

        if (glfwGetKey(this->window, GLFW_KEY_S) == GLFW_PRESS) {
            mainCamera->translate(-mainCamera->getForwardVector() * mainCamera->speed);
        }

        if (glfwGetKey(this->window, GLFW_KEY_A) == GLFW_PRESS) {
            mainCamera->translate(-mainCamera->getRightVector() * mainCamera->speed);
        }

        if (glfwGetKey(this->window, GLFW_KEY_D) == GLFW_PRESS) {
            mainCamera->translate(mainCamera->getRightVector() * mainCamera->speed);
        }
	}

}
