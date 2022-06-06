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
		void SetVelocity(const glm::vec3 &lineVelocity,const glm::vec3 &angVelocity);//�����ٶ�
		void SetMat(const glm::mat4& mat);
		void AddImpulse(const glm::vec3& point, const glm::vec3& impulse);//˲�����ӳ���
		void AddForce(const glm::vec3& point, const glm::vec3& force);//ʩ����
		void ClearForce();//����


	private:
		float Mass; //����
		float ElasticityCoefficient;//����ϵ��
		float FrictionCoefficient;//Ħ��ϵ��
		
		glm::vec3 MassCenter; //����
		glm::vec3 AllForces;//������
		glm::vec3 AllTorques;//������
		glm::vec3 LineVelocity;//���ٶ�
		glm::vec3 AngleVelocity;//���ٶ�
		glm::vec3 AngleMomentum;//�Ƕ���

		glm::mat3 RigidBodyInertiaTensor;//�ֲ���������
		glm::mat3 WorldInertiaTensor;//�����������

		glm::mat3 RotateMat;//��ת����
		glm::mat4 tranform;

		glm::vec3  ExtForces;         //������
		glm::vec3  ExtTorques;        //������

	};

}