#pragma once
#include "../../Core/shader.h"
#include <camera.h>
#include <glm/glm.hpp>
#include "../../Core/utils.h"
#include <vector>
using namespace std;

class  CascadeShadowMap
{
private:
	int CascadeNum;
	vector<vector<glm::vec4>> SplitPointList;
	void SplitDistance(Camera& camera);//������������߿ռ���ÿ��ƽ��ͷ����Ƭ�Ľ������Զ����
	void GetSplitPointByCamera(Camera& camera);
	void GetSplitPointByNDC(Camera& camera);
	void GetNewLightViewMat4(Camera& camera, glm::vec4 lightPos, glm::vec4 lightDirection);//����ÿ����Χ�еı任����

public:
	vector<float> CascadeFarPlaneDistantList;
	vector<glm::mat4> LightProViewMat4List;
	int GetCascadeNum() const;
	CascadeShadowMap(int _CascadeNum, Camera& camera);
	virtual~CascadeShadowMap();

	void UpdateCsm(Camera& camera, glm::vec4 lightPos, glm::vec4 lightDirection);
};