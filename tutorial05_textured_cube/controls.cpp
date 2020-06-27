/*****************************
*   Author: Anirudh Nistala  *
*   Roll No. B16091          *
*****************************/ 
// Include GLFW
#include <GLFW/glfw3.h>
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.
 
// Include GLM
#include <glm/glm.hpp>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;
 
#include "controls.hpp"
 
glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;
  
glm::mat4 getViewMatrix(){
   return ViewMatrix;
}
  
glm::mat4 getProjectionMatrix(){
   return ProjectionMatrix;
}
 
// Initial position : on +Z
glm::vec3 position_1 = glm::vec3( 0, 0, 0 );
 
// Initial horizontal angle : toward -Z
float horizontalAngle = 0.0f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
  
// Initial Field of View
float initialFoV = 45.0f;
 
float speed = 3.0f; // 3 units / second
float mouseSpeed_1 = 0.005f;
 
void computeMatricesFromInputs(){
 
   // glfwGetTime is called only once, the first time this function is called
   static double lastTime = glfwGetTime();
 
   // Compute time difference between current and last frame
   double currentTime = glfwGetTime();
   float deltaTime = float(currentTime - lastTime);
 
   // Get mouse position
   double xpos, ypos;
   glfwGetCursorPos(window, &xpos, &ypos);

   glm::vec3 up(0, 1, 0);
 
   // Strafe right
   if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
       horizontalAngle += deltaTime * speed;
 
       // Direction : Spherical coordinates to Cartesian coordinates conversion
       
       position_1 = glm::vec3(
           20*cos(verticalAngle_1)*sin(horizontalAngle_1),
           20*sin(verticalAngle_1),
           20*cos(horizontalAngle_1)*cos(verticalAngle_1)
       );
    }
   
   // Strafe left
   if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
       horizontalAngle -= deltaTime * speed;
 
       // Direction : Spherical coordinates to Cartesian coordinates conversion
      
 
       position_1 = glm::vec3(
           20*cos(verticalAngle_1)*sin(horizontalAngle_1),
           20*sin(verticalAngle_1),
           20*cos(horizontalAngle_1)*cos(verticalAngle_1)
       );
    }
 
   float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
 
   // Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
   ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
   // Camera matrix
   ViewMatrix1 = glm::lookAt(position_1, glm::vec3(0, 0, 0), up);
   // For the next frame, the "last time" will be "now"
   lastTime = currentTime;
}