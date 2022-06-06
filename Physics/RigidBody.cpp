#include "RigidBody.h"

namespace ManholeEngine
{
	RigidBody::RigidBody() 
	{

	}

	void RigidBody::SetPosition(const glm::vec3 &pos)
	{
		MassCenter = pos;

	}

	void RigidBody::SetVelocity(const glm::vec3 &lineVelocity, const glm::vec3 &angVelocity)
	{

	}


	void RigidBody::SetMat(const glm::mat4 &m)
	{


	}

	void RigidBody::AddImpulse(const glm::vec3& point, const glm::vec3& impulse)
	{

	}
	void RigidBody::ClearForce()
	{
		ExtForces = glm::vec3(0, 0, 0);
		ExtTorques = glm::vec3(0, 0, 0);
	}

	void RigidBody::AddForce(const glm::vec3& point, const glm::vec3& force)
	{
		ExtForces += force;
		glm::vec3 rc = point - MassCenter;//Á¦¾Ø
		ExtTorques += glm::cross(rc, force);
	}

}
