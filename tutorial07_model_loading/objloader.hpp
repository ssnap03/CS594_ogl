#ifndef OBJLOADER_H
#define OBJLOADER_H

bool loadOBJ(
	const char * path, 
	std::vector<glm::vec3> & out_vertices, 
	std::vector<glm::vec2> & out_uvs, 
	std::vector<glm::vec3> & out_normals
);

bool loadOBJ(
	const char * path,
	int &count, 
	std::vector<glm::vec3> & out_vertices1,
	std::vector<glm::vec3> & out_vertices2,
	std::vector<glm::vec2> & out_uvs1,
	std::vector<glm::vec2> & out_uvs2,
	std::vector<glm::vec3> & out_normals1,
	std::vector<glm::vec3> & out_normals2
);

bool loadAssImp(
	const char * path, 
	std::vector<unsigned short> & indices,
	std::vector<glm::vec3> & vertices,
	std::vector<glm::vec2> & uvs,
	std::vector<glm::vec3> & normals
);

#endif