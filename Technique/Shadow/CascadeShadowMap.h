#pragma once
#include "../Core/shader.h"
#include "../Core/sceneElements.h"
#include "../Core/ScreenSpaceShader.h"
#include "../External/imgui/imgui.h"
#include <camera.h>
#include <glm/glm.hpp>
#include "../../Core/utils.h"
#include <vector>
using namespace std;

class  CascadeShadowMap
{
private:
	Shader* ShadowMapShader, * ShadowMapDepth;
	int CascadeNum;
	vector<vector<glm::vec4>> SplitPointList;
	void SplitDistance(Camera& camera);//计算摄像机视线空间中每个平截头体切片的近距离和远距离
	void GetSplitPointByCamera(Camera& camera);
	void GetSplitPointByNDC(Camera& camera);
	void GetNewLightViewMat4(Camera& camera, glm::vec4 lightPos, glm::vec4 lightDirection);//计算每个包围盒的变换矩阵

public:
	vector<float> CascadeFarPlaneDistantList;
	vector<glm::mat4> LightProViewMat4List;
	int GetCascadeNum() const;
	CascadeShadowMap(int _CascadeNum, Camera& camera);
	virtual~CascadeShadowMap();


	void setGui();
	void initShaders();
	void generateModelTextures();
	void UpdateCsm(Camera& camera, glm::vec4 lightPos, glm::vec4 lightDirection);
};
