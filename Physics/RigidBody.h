#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace ManholeEngine
{
	class RigidBody
	{
	public:
		RigidBody();

		void SetPosition(const glm::vec3& pos);
		void SetVelocity(const glm::vec3 &lineVelocity,const glm::vec3 &angVelocity);//设置速度
		void SetMat(const glm::mat4& mat);
		void AddImpulse(const glm::vec3& point, const glm::vec3& impulse);//瞬间增加冲量
		void AddForce(const glm::vec3& point, const glm::vec3& force);//施加力
		void ClearForce();//清力


	private:
		float Mass; //质量
		float ElasticityCoefficient;//弹性系数
		float FrictionCoefficient;//摩擦系数
		
		glm::vec3 MassCenter; //质心
		glm::vec3 AllForces;//合外力
		glm::vec3 AllTorques;//合力矩
		glm::vec3 LineVelocity;//线速度
		glm::vec3 AngleVelocity;//角速度
		glm::vec3 AngleMomentum;//角动量

		glm::mat3 RigidBodyInertiaTensor;//局部惯性张量
		glm::mat3 WorldInertiaTensor;//世界惯性张量

		glm::mat3 RotateMat;//旋转矩阵
		glm::mat4 tranform;

		glm::vec3  ExtForces;         //合外力
		glm::vec3  ExtTorques;        //合力矩

	};

}