/*****************************
*	Authors:Arpit Bhadauria  *
*			 				 *
*			Anirudh Nistala  *
*						 	 *
*****************************/	
// Include GLFW
#include <GLFW/glfw3.h>
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include <glm/glm.hpp>
#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "controls.hpp"

glm::mat4 ViewMatrix1, ViewMatrix2;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix1(){
	return ViewMatrix1;
}

glm::mat4 getViewMatrix(){
	return ViewMatrix1;
}

glm::mat4 getViewMatrix2(){
	return ViewMatrix2;
}

glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}

// Initial position : on +Z
glm::vec3 position_1 = glm::vec3( 0, 0, 20 ); 
glm::vec3 position_2 = glm::vec3( 0, 0, 20 );

// Initial horizontal angle : toward -Z
float horizontalAngle_1 = 0.0f;
// Initial vertical angle : none
float verticalAngle_1 = 0.0f;

// Initial horizontal angle : toward -Z
float horizontalAngle_2 = 0.0f;
// Initial vertical angle : none
float verticalAngle_2 = 0.0f;

// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed_1 = 6.0f;
float mouseSpeed_2 = 3.0f;

void computeMatricesFromInputs(){

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1024/2, 768/2);

	//Compute new orientation

	verticalAngle_1  += mouseSpeed_1 * deltaTime * float( 768/2 - ypos );
	float val1 = (position_1.x/(20.0f*cos(verticalAngle_1)));
	if(val1 < -1.0f)
		val1 = -1.0f;
	if(val1 > 1.0f)
		val1 = 1.0f;
	horizontalAngle_1 = asin(val1);
	horizontalAngle_1 += mouseSpeed_1 * deltaTime * float(1024/2 - xpos );

	verticalAngle_2  += mouseSpeed_2 * deltaTime *float( 768/2 - ypos );
	float val2 = (position_2.x/(20.0f*cos(verticalAngle_2)));
	if(val2 < -1.0f)
		val2 = -1.0f;
	if(val2 > 1.0f)
		val2 = 1.0f;
	horizontalAngle_2 = asin(val2);
	horizontalAngle_2 += mouseSpeed_2 * deltaTime * float(1024/2 - xpos );

	glm::vec3 up(0, 1, 0);

	// Move forward
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		verticalAngle_1 += deltaTime * speed;
		verticalAngle_2 += deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		verticalAngle_1 -= deltaTime * speed;
		verticalAngle_2 -= deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		horizontalAngle_1 += deltaTime * speed;
		horizontalAngle_2 += deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		horizontalAngle_1 -= deltaTime * speed;
		horizontalAngle_2 -= deltaTime * speed;
	}

	position_1 = glm::vec3(
		20*cos(verticalAngle_1)*sin(horizontalAngle_1), 
		20*sin(verticalAngle_1),
		20*cos(horizontalAngle_1)*cos(verticalAngle_1)
	);

	position_2 = glm::vec3(
		20*cos(verticalAngle_2)*sin(horizontalAngle_2), 
		20*sin(verticalAngle_2),
		20*cos(horizontalAngle_2)*cos(verticalAngle_2)
	);

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix1 = glm::lookAt(position_1, glm::vec3(0, 0, 0), up);
	ViewMatrix2 = glm::lookAt(position_2, glm::vec3(0, 0, 0), up);
	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}