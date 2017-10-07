/* Hello Triangle - código fornecido em https://learnopengl.com/#!Getting-started/Hello-Triangle 
 *
 * Adaptado por Rossana Baptista Queiroz
 * para a disciplina de Computação Gráfica - Jogos Digitais - Unisinos
 * Versão inicial: 7/4/2017
 * Última atualização em 08/08/2017
 *
 */

#include "Buniby.h"




// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double posX, double posY);
// Window dimensions
Buniby engine;


GLfloat* DrawCircle(float p_radius, int p_points, int* vertexes)
{
	float __pi = 3.1415;
	p_points *= 3;
	*vertexes = p_points + 3;
	GLfloat* _resultArray = new GLfloat[*vertexes];
	_resultArray[0] = 0;
	_resultArray[1] = 0;
	_resultArray[2] = 0;
	
	float __angle = 2 * __pi;
	float __anglediff = __angle / ((p_points -3 )/3);
	__angle = 0;
	for (int i = 3; i < p_points + 3; i += 3)
	{
		_resultArray[i] = cos(__angle) * p_radius;
		_resultArray[i + 1] = sin(__angle) * p_radius;
		_resultArray[i + 2] = 0.0f;
		__angle += __anglediff;

	}
	
	return _resultArray;

}

GLfloat* CircleColors(int vertexnum)
{
	GLfloat* colorsDynamic = new GLfloat[vertexnum];
	for (int i = 0; i < vertexnum; i++)
	{
		colorsDynamic[i] = (float)(rand()%100) / 100.0f;
	}
	return colorsDynamic;
}




// The MAIN function, from here we start the application and run the game loop
int main()
{
	Screen::SetSize(800, 600);

	// Init GLFW
	glfwInit();
	srand(time(0));
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(Screen::WIDTH, Screen::HEIGHT, "Buniby", nullptr, nullptr);
	Screen::WINDOW = window;
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	/* get version info */
	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
	cout << "Renderer: " << renderer << endl;
	cout << "OpenGL version supported " << version << endl;

	// Define the viewport dimensions
	int width, height;
	
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	Shader* shaderLoader = new Shader("Vertex.vs", "Fragment.fs"); //carega os shaders
	
	glEnable(GL_DEPTH_TEST);

	ObjControl controller;
	Camera camera(vec3(0, 10, 5), vec3(-90, 0, 0));
	engine.SetCamera(&camera);
	engine.AddObject("M", "Pikachu.obj", 0, 5, 0);
	engine.AddObject("F", "PikachuF.obj", 5, 5, 0);
	engine.GetObject("F")->SetScale(0.1, 0.1, 0.1);
	controller.SetControlledObj(engine.GetObject("F"));


	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		engine.StartFrame();

		camera.Update();
		controller.Update();

		engine.EndFrame(shaderLoader);
		
	}
	engine.DealocateBuffers();
	glfwTerminate();
	return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && (action == GLFW_REPEAT || action == GLFW_PRESS))
		glfwSetWindowShouldClose(window, GL_TRUE);

	Input::RegisterKey(key, action);

}

void mouse_callback(GLFWwindow* window, double posX, double posY)
{
	Input::RegisterMouse(posX, posY);
}

