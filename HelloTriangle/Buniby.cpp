#include "Buniby.h"


Buniby::Buniby()
{
}


Buniby::~Buniby()
{
}

void Buniby::StartFrame()
{
	Time::FindDeltaTime();
	glfwPollEvents();
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}

void Buniby::EndFrame(Shader* shader)
{

	shader->use(); //utiliza o programa carregado do shader
						 //Camera
	glm::mat4 projection;
	camera_ptr->Update();
	projection = glm::perspective(45.0f, (GLfloat)Screen::WIDTH / (GLfloat)Screen::HEIGHT, 0.1f, 1000.0f);
	//Light Uniforms
	GLuint objColorLoc = glGetUniformLocation(shader->ID, "objectColor"); //pega o endereço dos uniforms
	GLint lightColorLoc = glGetUniformLocation(shader->ID, "lightColor");
	GLint lightPosLoc = glGetUniformLocation(shader->ID, "lightPos");
	GLint viewPosLoc = glGetUniformLocation(shader->ID, "viewPos");

	glUniform3f(objColorLoc, 1.0f, 0.0f, 1.0f); //atribui valor para os uniforms esta é a cor do objeto
	glUniform3f(lightColorLoc, 0.8f, 0.8f, 0.8f); //atribui valor para a cor da luz
	glUniform3f(lightPosLoc, -10, 1500, 3); //atribui valor para a posicao da luz
	glm::vec3 __camPos = camera_ptr->GetPosition();
	glUniform3f(viewPosLoc, __camPos.x, __camPos.y, __camPos.z); //posiçao da camera, temporariamente está fixa


	for (map<string, Object3D*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
	{

		GLint modelLoc = glGetUniformLocation(shader->ID, "model"); //Aqui pegamos o endereço da variavel no shader, para depois enviarmos o valor que queremos que o shader utilize
		GLint viewLoc = glGetUniformLocation(shader->ID, "view");
		GLint projectionLoc = glGetUniformLocation(shader->ID, "projection");
		Object3D* __obj = it->second;
		//Pass Uniform to Shader
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(__obj->GetModelMatrix())); //enviando o valor para o shader utilizar
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera_ptr->GetViewMatrix()));
		glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(__obj->VAO);
		glDrawElements(GL_TRIANGLES, __obj->GetFacesToDraw(), GL_UNSIGNED_INT, 0); // manda desenhar os vertices pelo EBO
		glBindVertexArray(0);

	}
	glfwSwapBuffers(Screen::WINDOW);
}

void Buniby::DealocateBuffers()
{
	for (map<string, Object3D*>::iterator it = _objects.begin(); it != _objects.end(); ++it)
	{
		Object3D* obj = it->second;
		glDeleteVertexArrays(1, &obj->VAO);
		glDeleteBuffers(1, &obj->VBO);
		glDeleteBuffers(1, &obj->nVBO);
	}
}
